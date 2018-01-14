/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:15:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/14 20:09:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Map_hpp
#define Map_hpp

# include <iostream>
# include <string>
# include <ncurses.h>
# include "Entity.hpp"

class Map {

    public:

        Map();
        Map(int H, int W);
        Map(Map const &src);
        ~Map();

        Map&           operator=(Map const &rhs);

        void        draw(); // a faire
        void        update(); // a faire

        void        deleteMap(); // free la Map
        bool        pos_in_map(int h, int w);

        int         addEntity(Entity *entity, int h, int w); // ajoute une entity au tableau sauf si entity deja presente
        int         addEntity(Entity *entity, int h, int w, int b); // if true ecrase l element en dessous, false comportement par default voir au dessus
        void        deleteEntity(int h, int w); // supprime une entity au tableu
		void		moveEntity(int h, int w, int newH, int newW);

        Entity*     getElem(int H, int W);

		void        update_background();

        void       setH(int const H);
        int        getH() const;
        void       setW(int const W);
        int        getW() const;
        Entity***  getMap();



    private:

        int             _H;
        int             _W;
        static Entity   ***_map;
        static int      **_background;


        void            _swap(Entity *entity, int h, int w);
        void            _draw(WINDOW **win, Entity *entity, int h, int w);

};



#endif /* Map_hpp */
