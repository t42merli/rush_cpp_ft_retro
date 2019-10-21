/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:42:52 by tmerli            #+#    #+#             */
/*   Updated: 2019/10/20 21:30:45 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Define.hpp"
#include "Game.class.hpp"

int main(void)
{
    int input;
    Game *game;
    int run = 1;
    int frame = 0;
    int c;

    srand(time(NULL));
    initscr();
    start_color();
    noecho();
    curs_set(0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    game = new Game();
    while (run != -1)
    {
        input = wgetch(game->win);
        napms(1);
        run = game->update(input, frame);
        if (run == 0)
        {
            nodelay(game->win, false);
            wclear(game->win);
            mvwprintw(game->win, WIN_SIZEY / 2, 30, "Score: %i", game->score);
            mvwprintw(game->win, WIN_SIZEY / 2 + 5, 30, "Try again, press any key. (ESC to quit)");
            wrefresh(game->win);
            napms(1000);
            c = wgetch(game->win);
            if (c == 27)
                run = -1;
            else
            {
                delete game;
                game = new Game();
                frame = -1;
            }
        }
        frame = (frame + 1) % (2880);
    }
    delete game;
    endwin();
}
