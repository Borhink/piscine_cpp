/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:15:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/13 20:38:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

Map::Map()
{
}

Map::Map(int H, int W)
{
    int i;
    int j;

    if (H && W && _map == NULL)
    {
        Map::_map = new Entity **[H];

        i = 0;
        while (i < H)
        {
            Map::_map[i] = new Entity*[W];
            j = 0;
            while (j < W)
            {
                Map::_map[i][j] = NULL;
                j++;
            }
            i++;
        }
        this->setH(H);
        this->setW(W);
    }
}

Map::Map(Map const &src)
{
    *this = src;
}

Map::~Map()
{
}

Map&            Map::operator=(Map const &rhs)
{
    if (Map::_map != NULL)
        deleteMap();
    setH(rhs.getH());
    setW(rhs.getW());
    Map::_map = getMap();
    return (*this);
}

void        Map::draw()
{
    WINDOW *win;
    int   w;
    int   h;
    //int col;
    //int row;

    win = newwin(50, 200, 2, 0);
    werase(win);
    //box(win, 0 , 0); // bordure blanche autour zone
    h = 0;
    //printw("%d, %d \n" ,this->_H, this->_W);
    while (h < this->_H)
    {
        w = 0;
        //printw("test \n");
        while (w < this->_W)
        {

            if (this->_map[h][w] != NULL)
            {

                //wprintw(win, "hi \n");
                //mvwprintw(win, h, w, ">");
                this->_draw(&win, this->_map[h][w], h, w);
            }
            else{
                //mvwprintw(win, h, w, " ");
            }
            //mvwprintw(win, h, w, "t");
            w++;
        }
        h++;
    }
    wrefresh(win);
    delwin(win);
    //getmaxyx(stdscr,row,col);
    //printw("%d, %d \n" ,row, col);
    //wprintw(win, "%d, %d \n" ,row, col);
    //mvwprintw(win, 24, 8, "test");
    //mvwprintw(win, 9, 9, "test");
    //mvwprintw(win, 10, 10, "test");

}

void       Map::_draw(WINDOW **win, Entity *entity, int h, int w)
{
    // verifier les types joueurs ou enemy pour le dessins
    mvwprintw(*win, h, w, ">");
	(void)entity;
}

void        Map::_swap(Entity *entity, int h, int w)
{
    Entity *tmp;

    tmp = entity;
    if (tmp && tmp->getX() != h && tmp->getY() != w) // future boucle
    {
        if (this->pos_in_map(tmp->getX(), tmp->getY()))
        {
            if (Map::_map[tmp->getX()][tmp->getY()])
            {
                tmp = Map::_map[tmp->getX()][tmp->getY()];
                Map::_map[tmp->getX()][tmp->getY()] = entity;
            }
            else
            {
                Map::_map[tmp->getX()][tmp->getY()] = tmp;
                Map::_map[h][w] = NULL;
            }
        }
    }
}

void       Map::update()
{
    int   w;
    int   h;

    h = 0;
    while (h < this->_H)
    {
        w = 0;
        while (w < this->_W)
        {
            if (this->_map[h][w] != NULL)
                this->_swap(this->_map[h][w], h, w);
            w++;
        }
        h++;
    }
}

/*
void        Map::clearMap()
{
    int i;
    int j;

    i = 0;
    while (i < this->_H)
    {
        j = 0;
        while (j < this->_W)
        {
            if (Map::_map[i][j])
                delete Map::_map[i][j];
            j++;
        }
        i++;
    }
}
*/

void        Map::deleteMap()
{
    int i;

    i = 0;
    while (i < this->_H)
    {
        delete [] Map::_map[i];
        i++;
    }
	delete [] Map::_map;
}

int        Map::addEntity(Entity *entity, int h, int w)
{
    if (this->pos_in_map(h, w) && !Map::_map[h][w])
    {
        Map::_map[h][w] = entity;
        return (1);
    }
    return (0);
}

int        Map::addEntity(Entity *entity, int h, int w, int b)
{
    if (this->pos_in_map(h, w))
    {
        if (Map::_map[h][w] && b)
            delete _map[h][w];
        Map::_map[h][w] = entity;
        return (1);
    }
    return (0);
}

void        Map::deleteEntity(int h, int w) // a tester
{
    if (this->pos_in_map(h, w) && Map::_map[h][w])
        delete Map::_map[h][w];
}

// void		Map::moveEntity(Entity *entity, int newH, int newW)
// {
// 	int h = e->getY();
// 	int w = e->getX();
// 	//Si l'entite existe et que la nouvelle position est libre
// 	if (this->_pos_in_map(h, w) && Map::_map[h][w]
// 		&& this->_pos_in_map(newH, newW) && Map::_map[newH][newW])
// 	{
// 		Map::_map[newH][newW] = Map::_map[h][w]; // On copie le pointeur
// 		Map::_map[h][w] = NULL; // Et on libere l'ancienne case
// 	}
// }

Entity*     Map::getElem(int H, int W)
{
    if (this->pos_in_map(H, W))
        return (Map::_map[H][W]);
    return (NULL);
}

void       Map::setH(int const H)
{
    this->_H = H;
}

int        Map::getH() const
{
    return (this->_H);
}

void       Map::setW(int const W)
{
    this->_W = W;
}

int        Map::getW() const
{
    return (this->_W);
}

Entity***       Map::getMap()
{
    return (Map::_map);
}

bool            Map::pos_in_map(int h, int w)
{
    if (h >= this->getH() || w >= this->getW() || h < 0 || w < 0)
        return (false);
    return (true);
}

Entity      ***Map::_map = NULL;
