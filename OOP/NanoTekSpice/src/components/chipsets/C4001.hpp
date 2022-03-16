/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4001 : public AComponent {
        public:
            C4001();
            ~C4001();
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
    };
}

#endif /* !C4001_HPP_ */
