//
// Created by francesco on 27/11/22.
//

#include "AdamsBashforth.h"
#include <iostream>

void AdamsBashforth::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

// We have to compute the first 's' solutions (we will use forward euler, for instance)
    sol.emplace(t0, y0);

    for (int i = 1; i < s; i++) {
        double t = t0 + h * i;
        double y = sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
        sol.emplace(t, y);
    }

    std::cout << "I have computed the first " << s << " solutions with Forward Euler" << std::endl;

// Now, depending on the particular numbers of steps,
// a different implementation of Adams-Bashforth method is applied
    if (s == 1) {                                                           // this would simply be forward Euler
        for (int i = s; i <= N; i++) {
            double t = t0 + h * i;
            double y = sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
            sol.emplace(t, y);
        }
    } else if (s == 2) {
        for (int i = s; i <= N; i++) {
            double t = t0 + h * i;
            double y = sol.rbegin()->second + h * (3.0 / 2.0 * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second)
                                                - 0.5 *
                                                this->funObject->EvaluateFun(std::prev(sol.rbegin(), -1)->first, std::prev(sol.rbegin(), -1)->second));

            std::cout << y << std::endl;
            sol.emplace(t, y);
        }
    } else if (s == 3) {
        for (int i = s; i <= N; i++) {
            double t = t0 + h * i;
            double y = sol.rbegin()->second + h * (23. / 12. * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second)
                                                - 16. / 12. *
                                                  this->funObject->EvaluateFun(std::prev(sol.rbegin(), 1)->first, std::prev(sol.rbegin(), 1)->second)
                                                + 5. / 12. *
                                                  this->funObject->EvaluateFun(std::prev(sol.rbegin(), 2)->first, std::prev(sol.rbegin(), 2)->second));
            sol.emplace(t, y);
        }
    } else if (s == 4) {
        for (int i = s; i <= N; i++) {
            double t = t0 + h * i;
            double y = sol.rbegin()->second + h * (55. / 24. * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second)
                                                - 59. / 24. *
                                                  this->funObject->EvaluateFun(std::prev(sol.rbegin(), 1)->first, std::prev(sol.rbegin(), 1)->second)
                                                + 37. / 24. *
                                                  this->funObject->EvaluateFun(std::prev(sol.rbegin(), 2)->first, std::prev(sol.rbegin(), 2)->second)
                                                - 9. / 24. *
                                                this->funObject->EvaluateFun(std::prev(sol.rbegin(), 3)->first, std::prev(sol.rbegin(), 3)->second));
            sol.emplace(t, y);
        }
    }
}