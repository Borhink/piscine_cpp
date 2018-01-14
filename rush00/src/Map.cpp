/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:15:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/14 20:08:08 by qhonore          ###   ########.fr       */
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

    if (H && W && _map == NULL && _background == NULL)
    {
        if (_map == NULL)
        {
            Map::_map = new Entity **[H];
            Map::_background = new int *[H];

            i = 0;
            while (i < H)
            {
                Map::_map[i] = new Entity*[W];
                Map::_background[i] = new int[W];
                j = 0;
                while (j < W)
                {
                    Map::_background[i][j] = 0;
                    Map::_map[i][j] = NULL;
                    j++;
                }
                i++;
            }
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
	this->deleteMap();
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

    win = newwin(this->_H + 2, this->_W + 2, 4, 1);
    werase(win);
    box(win, 0 , 0); // bordure blanche autour zone
    h = 0;
    while (h < this->_H)
    {
        w = 0;
        while (w < this->_W)
        {
			if (this->_map[h][w] == NULL && Map::_background[h][w] == 1 && w > 0 && h > 0)
            {
                mvwprintw(win, h, w, ".");
            }
            if (this->_map[h][w] != NULL)
            {
				this->_draw(&win, this->_map[h][w], h, w);
            }
            w++;
        }
        h++;
    }
    wrefresh(win);
    delwin(win);

}

void        Map::update_background()
{
    int random = rand() % this->_H;
    int h;
    int w;

    h = 0;
    while (h < this->_H)
    {
        w = 0;
        while (w < this->_W)
        {
            if (Map::_background[h][w])
            {
                if (this->pos_in_map(h, w - 1))
                {
                    Map::_background[h][w] = 0;
                    Map::_background[h][w - 1] = 1;
                }
                else
                {
                    Map::_background[h][w] = 0;
                }
            }
            w++;
        }
        h++;
    }
    Map::_background[random][this->_W - 1] = 1;
}

void       Map::_draw(WINDOW **win, Entity *entity, int h, int w)
{
    // verifier les types joueurs ou enemy pour le dessins
	if (entity->getType() == PLAYER)
		wattron(*win, COLOR_PAIR(2));
	else if (entity->getType() == P_PROJECTILE)
		wattron(*win, COLOR_PAIR(3));
	else if (entity->getType() == ENEMY)
		wattron(*win, COLOR_PAIR(4));
	else if (entity->getType() == E_PROJECTILE)
		wattron(*win, COLOR_PAIR(5));
	char tab[2] = {entity->getName(), 0};
    mvwprintw(*win, h + 1, w + 1, tab);
	wattron(*win, COLOR_PAIR(1));
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
			{
				this->_map[h][w]->update();
			}
            w++;
        }
        h++;
    }
}

void        Map::deleteMap()
{
	int i;

    i = 0;
    while (i < this->_H)
    {
        delete [] Map::_background[i];
        delete [] Map::_map[i];
        i++;
    }
	delete [] Map::_map;
    delete [] Map::_background;
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
	{
        delete Map::_map[h][w];
		Map::_map[h][w] = NULL;
	}
}

void		Map::moveEntity(int h,int w, int newH, int newW)
{
 	//Si l'entite existe et que la nouvelle position est libre
 	if (this->pos_in_map(h, w) && Map::_map[h][w]
 		&& this->pos_in_map(newH, newW) && !Map::_map[newH][newW])
 	{
 		Map::_map[newH][newW] = Map::_map[h][w];
 		Map::_map[h][w] = NULL;
 	}
}

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

int         **Map::_background = NULL;
Entity      ***Map::_map = NULL;
