
#include"BASE_FUNCITION.h"
#include"Game.h"
#include"Time.h"
#include"Plane.h"
#include"Threat.h"
#include"Amo.h"
#include"Explosion.h"
#include"TextOB.h"
#include"PLAYER_PW.h"
#include"Boss.h"
#include"Menu.h"

Game menu;
Game img_background;
TTF_Font *font_time = NULL;
Plane player;
Game player_start;
Explosion exp_threat;
Boss boss_game;

Time fbs;

int bkground_x = 0;
int num_die = MAX_NUM_DIE;

int num_threat = 0;
void close() {
    img_background.Clean();

    SDL_DestroyRenderer(screen);

    screen = NULL;

    SDL_DestroyWindow(window);

    window = NULL;

    IMG_Quit();
    SDL_Quit();

}


bool initSDL() {
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;
    else {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        window = SDL_CreateWindow("Game Thucdzio", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            success = false;
        }
        else {
            screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (screen == NULL) {
                success = false;
            }
            else {
                SDL_SetRenderDrawColor(screen, r_color, g_color, b_color, 256);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) && imgFlags))
                    success = false;
            }
            if (TTF_Init() == -1)
            {
                success = false;
            }
            
            font_time = TTF_OpenFont("font//lazy.ttf", 30);
            if (font_time == NULL)
            {
                success = false;
            }
      }

    }
    return success;
}
bool Load_background() {
    bool rec = img_background.LoadImg("img//background.png", screen);
    if (rec == false) return false;
    return true;
}
bool start()
{
    Menu menu;
    
    bool is_quit = false;
    int  res_menu = menu.showMenu(screen);
    
    if (res_menu == 1)
    {
        is_quit = true;
    }
    else if (res_menu == 2)
    {
        int x = menu.renderTutorial(screen);
        if (x == 0) {
            menu.Clean();
        }
        else if (x == 1) {
            is_quit = true;
        }
    }
    
    else if (res_menu == 0)
    {
        menu.Clean();

    }
    return is_quit;
    
}
bool is_replay() {
    Game end_game;
    end_game.LoadImg("img//end.png", screen);
    end_game.Set_Rect(0, -100);
    end_game.Render(screen);

    SDL_RenderPresent(screen);
    SDL_Delay(2000);
    player.Clean();

    Menu replay;
    int x = replay.CheckReplay(screen);
    if (x == 0) {
        return true;
    }
    
    return false;
}
bool end() {
    Game win_game;
    win_game.LoadImg("img//win.png", screen);
    win_game.Set_Rect(-50, -100);
    win_game.Render(screen);

    SDL_RenderPresent(screen);
    SDL_Delay(2000);

    Menu replay;
    int x = replay.CheckReplay(screen);
    if (x == 0) {
        return true;
    }

    return false;
}

bool play() {
    //Plane
    player.LoadImg("img//Right.png", screen);

    Health player_power;
    player_power.Init(screen);
    // Tao vu no

    exp_threat.set_clip();

    // Text
    Text mark_game;
    mark_game.SetColor(Text::WHITE_TEXT);
    UINT mark_value = 0;

    Text Hp_boss;
    Hp_boss.SetColor(Text::WHITE_TEXT);
    UINT num_boss_die = 50;

    // Threat 

    Threat* p_threats = new  Threat[NUM_THREAT];
    for (int i = 0; i < NUM_THREAT; i++) {

        Threat* p_threat = p_threats + i;

        bool ret = p_threat->LoadImg("img//threat.png", screen);

        int rand_y = rand() % 700;
        if (rand_y > SCR_HEIGHT - 100) {
            rand_y = 200;
        }

        p_threat->set_now(SCR_WIDTH + i * 300, rand_y);
        p_threat->set_x(3);

        Amo* p_amo = new Amo();
        p_amo->LoadImg("img//amo_threat.png", screen);
        p_threat->Init_Amo(p_amo);

    }
    //Boss

    boss_game.LoadImg("img//boss.png", screen);
    boss_game.setx(2);
    boss_game.Set_Rect(SCR_WIDTH - 550, 100);

    // Tao threat boss

    Threat* bs_threats = new  Threat[NUM_THREAT];
    for (int bs = 0; bs < NUM_THREAT; bs++) {

        Threat* bs_threat = bs_threats + bs;

        bool ret_bs = bs_threat->LoadImg("img//boom.png", screen);

        int rand_x = rand() % 1200;
        if (rand_x > SCR_WIDTH - 100) {
            rand_x = 300;
        }

        bs_threat->set_now(rand_x, 0 - bs * 200);
        bs_threat->set_y(3);
    }

    // Code
    bool is_quit = false;
    while (!is_quit) {
        fbs.start();
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                is_quit = true;
            }

            player.Input_Player(event, screen);
        }
        SDL_SetRenderDrawColor(screen, r_color, g_color, b_color, 256);
        SDL_RenderClear(screen);
        //background 
        bkground_x -= SCR_SPEED;

        img_background.Set_Rect(bkground_x, 0);
        img_background.Render(screen);
        img_background.Set_Rect(bkground_x + SCR_WIDTH, 0);
        img_background.Render(screen);
        if (bkground_x <= -SCR_WIDTH) bkground_x = 0;


        // Run main

        player.doPlayer();
        player.do_Skill(screen);
        player.Amo_do(screen);
        player.Show(screen);

        // Mang

        player_power.Show(screen);

        // run Threat
        for (int a = 0; a < NUM_THREAT; a++) {
            Threat* p_threat = p_threats + a;
            p_threat->doThreat();
            p_threat->Show(screen);
            p_threat->Amo_do(screen);

            //Vc cua dan va quai
            vector < Amo* > amo_arr = player.get_amo_list();
            for (int am = 0; am < amo_arr.size(); am++)
            {
                Amo* p_amo = amo_arr.at(am);//
                if (p_amo) {
                    bool is_col = SDL_FUNC::CheckCollision(p_threat->GetRect(), p_amo->GetRect());
                    if (is_col)
                    {
                        mark_value++;
                        num_threat++;
                        for (int ex = 0; ex < 4; ++ex) {
                            int x_pos = p_threat->GetRect().x - 80;
                            int y_pos = p_threat->GetRect().y - 80;

                            exp_threat.set_frame(ex);

                            exp_threat.Set_Rect(x_pos, y_pos);

                            exp_threat.Show_Ex(screen);

                        }
                        player.Clean_Amo();
                        p_threat->Reset_Amo(p_threat);
                        p_threat->Clean();
                    }
                }
            }

            vector <Amo* > amo_threat = p_threat->get_amo_list();
            for (int a_t = 0; a_t < amo_threat.size(); ++a_t) {
                Amo* t_amo = amo_threat.at(a_t);
                if (t_amo) {
                    bool Coll = SDL_FUNC::CheckCollision(player.GetRect(), t_amo->GetRect());
                    if (Coll) {
                        Explosion exp_player;
                        exp_player.LoadImg("img//exp.png", screen);

                        exp_player.set_clip();
                        for (int ax = 0; ax < 4; ++ax) {
                            int x_pos = t_amo->GetRect().x - 50;
                            int y_pos = t_amo->GetRect().y - 50;

                            exp_player.set_frame(ax);
                            exp_player.Set_Rect(x_pos, y_pos);
                            exp_player.Show_Ex(screen);

                        }
                        num_die--;
                        if (num_die >= 0) {

                            player.set_now(0, 0);
                            player_power.Decrease();
                            player_power.Render(screen);

                            continue;
                        }
                        else {
                            if (!is_replay) {
                                SDL_Quit();
                            }
                            else {
                                return true;
                            }
                        }


                    }


                }
            }
        }
        // run Boss
        if (num_threat == NUM_THREAT) {
            boss_game.do_Boss();
            boss_game.Show_Boss(screen);
            if (boss_game.get_x_pos() < 0) {
                int xb = rand() % 1000;
                int yb = rand() % 500;
                boss_game.Set_Rect(xb, yb);
            }
            // run threat
            for (int ab = 0; ab < NUM_THREAT; ab++) {

                Threat* bs_threat = bs_threats + ab;

                bs_threat->doThreat();
                bs_threat->Show(screen);

                bool boom_Col = SDL_FUNC::CheckCollision(bs_threat->GetRect(), player.GetRect());
                if (boom_Col)
                {
                    num_die--;
                    if (num_die >= 0) {

                        player.set_now(0, SCR_HEIGHT / 2);
                        player_power.Decrease();
                        player_power.Render(screen);
                        continue;
                    }
                    else {
                        if (!is_replay) {
                            SDL_Quit();
                        }
                        else {
                            return true;
                        }
                    }
                }
            }


            //Vc dan va boss
            vector < Amo* > list_amo = player.get_amo_list();
            for (int amb = 0; amb < list_amo.size(); amb++)
            {
                Amo* b_amo = list_amo.at(amb);//
                if (b_amo) {
                    bool boss_col = SDL_FUNC::CheckCollision(boss_game.GetRect(), b_amo->GetRect());
                    if (boss_col)
                    {
                        num_boss_die--;
                        mark_value++;
                        Explosion exp_main;
                        exp_main.LoadImg("img//exp.png", screen);

                        exp_main.set_clip();
                        for (int ex = 0; ex < 4; ++ex) {
                            int x_pos = b_amo->GetRect().x - 80;
                            int y_pos = b_amo->GetRect().y - 80;

                            exp_main.set_frame(ex);
                            exp_main.Set_Rect(x_pos, y_pos);
                            exp_main.Show_Ex(screen);

                        }

                        player.Clean_Amo();
                        if (num_boss_die == 0) {
                            boss_game.Clean();
                           
                            if (!end()) {
                                SDL_Quit();
                            }
                            else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        // Vc main vs boss
        bool is_mb = SDL_FUNC::CheckCollision(player.GetRect(), boss_game.GetRect());
        if (is_mb) {
            num_die--;
            if (num_die >= 0) {

                player.set_now(0, SCR_HEIGHT / 2);
                player_power.Decrease();
                player_power.Render(screen);
                continue;
            }
            else {
                if (!is_replay) {
                    SDL_Quit();
                }
                else {
                    return true;
                }
            }
        }

        //Show Mark 

        string val_str_mark = to_string(mark_value);
        string strMark("MARK :  ");
        strMark += val_str_mark;

        mark_game.Set_Text(strMark);
        mark_game.Load_TEXT(font_time, screen);
        mark_game.Render_Text(screen, SCR_WIDTH - 170, 20);

        //SHow Hp_boss
        string val_hp = to_string(num_boss_die);
        string strHp("HP BOSS :  ");
        strHp += val_hp;

        Hp_boss.Set_Text(strHp);
        Hp_boss.Load_TEXT(font_time, screen);
        Hp_boss.Render_Text(screen, SCR_WIDTH / 2, 20);

        SDL_RenderPresent(screen);

        //fbs
        int real_time = fbs.Get_Time();
        int one_time = 1000 / FBS_GAME;

        if (real_time < one_time) {
            int delay_time = one_time - real_time;
            if (delay_time >= 0)
                SDL_Delay(delay_time);
        }

    }
    return 0;
}
int main(int argc, char* argv[]) {
    

    if (initSDL() == false)
    {
        return -1;
    }
    if (Load_background() == false) {
        return -1;
    }
    bool status = true;
    while ( status ) {
        
        if (!start()) {
            if (!play()) {
                status = false;
                return 0;
            } 
            
        }
        else {
            status = false;
            return 0;
        }
    }
    close();
    return 0;
}

