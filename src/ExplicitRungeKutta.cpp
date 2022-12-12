//
// Created by parallels on 12/4/22.
//

#include "ExplicitRungeKutta.h"

void ExplicitRungeKutta::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

    // We set the initial condition
    sol.emplace(t0, y0);

    // Now depending on the variable 'stages', a different method will be applied
    if (stages == 1) {
        // This will be Forward Euler
        for (int i = 1; i <= N; i++) {
            double t = this->t0 + this->h * i;

            // Here we compute k1
            double k1 = this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);

            double y = sol.rbegin()->second + h * k1;
            sol.emplace(t, y);
        }

    } else if (stages == 2) {
        // This will coincide with Heun method
        for (int i = 1; i <= N; i++) {
            double t = this->t0 + this->h * i;

            // Here we compute k1 and k2
            double k1 = this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
            double k2 = this->funObject->EvaluateFun(sol.rbegin()->first + this->h, sol.rbegin()->second + h * k1);

            double y = sol.rbegin()->second + 0.5 * h * (k1 + k2);
            sol.emplace(t, y);
        }

    } else if (stages == 3) {
        // As three stages Runge Kutta, we chose the Third-order Strong Stability Preserving Runge-Kutta (SSPRK3)
        for (int i = 1; i <= N; i++) {
            double t = t0 + h * i;

            // We calculate k1, k2 and k3
            double k1 = this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
            double k2 = this->funObject->EvaluateFun(sol.rbegin()->first + h, sol.rbegin()->second + h * k1);
            double k3 = this->funObject->EvaluateFun(sol.rbegin()->first + 0.5 * h, sol.rbegin()->second + 0.25 * h * (k1 + k2));

            double y = sol.rbegin()->second + h * (1. / 6. * k1 + 1. / 6. * k2 + 2. / 3. * k3);
            sol.emplace(t, y);
        }

    } else if (stages == 4) {
        // This is the standard Runge Kutta method
        for (int i = 1; i <= N; i++) {
            double t = t0 + h * i;

            // We calculate k1, k2, k3 and k4
            double k1 = this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
            double k2 = this->funObject->EvaluateFun(sol.rbegin()->first + 0.5 * h, sol.rbegin()->second + 0.5 * h * k1);
            double k3 = this->funObject->EvaluateFun(sol.rbegin()->first + 0.5 * h, sol.rbegin()->second + 0.5 * h * k2);
            double k4 = this->funObject->EvaluateFun(sol.rbegin()->first + h, sol.rbegin()->second + h * k3);

            double y = sol.rbegin()->second + (1.0 / 6.0) * h * (k1 + 2 * k2 + 2 * k3 + k4);
            sol.emplace(t, y);
        }
    }
}