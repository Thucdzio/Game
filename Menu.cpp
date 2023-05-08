#include"Menu.h"

Menu::Menu() {

}

Menu :: ~Menu() {

}
int Menu::CheckReplay(SDL_Renderer* des)
{
    Game replay, exit;

    replay.LoadImg("img//button_replay.png", des);
    replay.Set_Rect(0, 0);
    replay.Render(des);

    exit.LoadImg("img//button_exit.png", des);
    exit.Set_Rect(0, 100);
    exit.Render(des);

    int xm = 0, ym = 0;
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT)
            {
                return -1;
                break;
            }
            else if (e.type == SDL_MOUSEMOTION) {
                xm = e.motion.x;
                ym = e.motion.y;
                if (SDL_FUNC::Checkfocus(xm, ym, replay.GetRect())) {
                    replay.Set_Rect(0, 0);
                    replay.LoadImg("img//button_replay_op.png", des);
                    replay.Render(des);
                }
                else {
                    replay.Set_Rect(0, 0);
                    replay.LoadImg("img//button_replay.png", des);
                    replay.Render(des);
                }
                if (SDL_FUNC::Checkfocus(xm, ym, exit.GetRect())) {
                    exit.Set_Rect(0, 100);
                    exit.LoadImg("img//button_exit_op.png", des);
                    exit.Render(des);
                }
                else {
                    exit.Set_Rect(0, 100);
                    exit.LoadImg("img//button_exit.png", des);
                    exit.Render(des);
                }
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                xm = e.motion.x;
                ym = e.motion.y;
                if (SDL_FUNC::Checkfocus(xm, ym, replay.GetRect())) {
                    return 0;
                }
                else if (SDL_FUNC::Checkfocus(xm, ym, exit.GetRect())) {
                    return 1;
                }
                break;
            }
        }
        SDL_RenderPresent(des);
    }
}
int Menu::renderTutorial(SDL_Renderer * des) {
    img_tutorial.LoadImg("img//huongdan.png", des);
    
    img_tutorial.Set_Rect(100, 200);
    img_tutorial.Render(des);
   

    Game start , exit;

    start.LoadImg("img//button_start.png", des);
    start.Set_Rect(0, 0);
    start.Render(des);

    exit.LoadImg("img//button_exit.png", des);
    exit.Set_Rect(0, 100);
    exit.Render(des);

    int xm = 0, ym = 0;
    SDL_Event e;
   
    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT)
            {
                return -1;
                break;
            }
            else if (e.type == SDL_MOUSEMOTION) {
                xm = e.motion.x;
                ym = e.motion.y;
                if (SDL_FUNC::Checkfocus(xm, ym, start.GetRect())) {
                    start.Set_Rect(0, 0);
                    start.LoadImg("img//button_start_op.png", des);
                    start.Render(des);
                }
                else {
                    start.Set_Rect(0, 0);
                    start.LoadImg("img//button_start.png", des);
                    start.Render(des);
                }
                if (SDL_FUNC::Checkfocus(xm, ym, exit.GetRect())) {
                    exit.Set_Rect(0, 100);
                    exit.LoadImg("img//button_exit_op.png", des);
                    exit.Render(des);
                }
                else {
                    exit.Set_Rect(0, 100);
                    exit.LoadImg("img//button_exit.png", des);
                    exit.Render(des);
                }
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                xm = e.motion.x;
                ym = e.motion.y;
                if (SDL_FUNC::Checkfocus(xm, ym, start.GetRect())) {
                    return 0;
                }
                else if (SDL_FUNC::Checkfocus(xm, ym, exit.GetRect())) {
                    return 1;
                }
                break;
            }
        }
        SDL_RenderPresent(des);
    }
 }

    



int Menu::showMenu(SDL_Renderer* screen) {
    bool res = g_image.LoadImg("img//main.png", screen);
    if (!res) {
        cout << "help" << endl;
    }
    const int number_of_items = 3;
    Game base[number_of_items];
    base[0].Set_Rect(100, 240);
    base[0].LoadImg("img//button_start.png", screen);
    base[1].Set_Rect(100, 310);
    base[1].LoadImg("img//button_exit.png", screen);
    base[2].Set_Rect(100, 380);
    base[2].LoadImg("img//button_about.png", screen);
    
    
    int xm = 0, ym = 0;
    SDL_Event m_event;
    while (true) {
        g_image.Set_Rect(0, 0);
        g_image.Render(screen);
        for (int i = 0; i < number_of_items; i++) {
            base[i].Render(screen);
        }
        while (SDL_PollEvent(&m_event) != 0) {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
                break;
            case SDL_MOUSEMOTION:
            {
                xm = m_event.motion.x;
                ym = m_event.motion.y;
                if (SDL_FUNC::Checkfocus(xm, ym, base[0].GetRect())) {
                    base[0].Set_Rect(100, 240);
                    base[0].LoadImg("img//button_start_op.png", screen);
                }
                else {
                    base[0].Set_Rect(100, 240);
                    base[0].LoadImg("img//button_start.png", screen);
                }
                if (SDL_FUNC::Checkfocus(xm, ym, base[1].GetRect())) {
                    base[1].Set_Rect(100, 310);
                    base[1].LoadImg("img//button_exit_op.png", screen);
                }
                else {
                    base[1].Set_Rect(100, 310);
                    base[1].LoadImg("img//button_exit.png", screen);
                }
                if (SDL_FUNC::Checkfocus(xm, ym, base[2].GetRect())) {
                    base[2].Set_Rect(100, 380);
                    base[2].LoadImg("img//button_about_op.png", screen);
                }
                else {
                    base[2].Set_Rect(100, 380);
                    base[2].LoadImg("img//button_about.png", screen);
                }
                
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                //Mix_PlayChannel(-1, click, 0);
                for (int i = 0; i < number_of_items; i++) {
                    if (SDL_FUNC::Checkfocus(xm, ym, base[i].GetRect())) {
                        return i;
                    }
                }
            }
            break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE) {
                    return 1;
                }
                break;
            }
        }
        SDL_RenderPresent(screen);
    }
    return 1;
}