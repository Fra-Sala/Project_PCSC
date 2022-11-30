//
// Created by francesco on 27/11/22.
//



#include "AdamsBashforth.h"


//AdamsBashforth::solve(){
//int N = round((tf - t0) / h);
//
//// We have to compute the first 's' solutions (we will use forward euler, for instance)
//sol.insert({t0, y0});
//
//for(int i = 1; i <= s; i++) {
//double t = t0 + h * i;
//double y = sol.end()->second + h * rhs(sol.end()->second, sol.end()->first);
//sol.insert({t, y});
//}
//
//// Now, depending on the particular numbers of steps,
//// a different implementation of Adams-Bashforth metod is applied
//if (s == 1) {                                                           // this would simply be forward Euler
//for(int i = (s + 1); i <= N; i++)  {
//double t = t0 + h * i;
//double y = sol.end()->second + h * rhs(sol.end()->second, sol.end()->first);
//sol.insert({t, y});
//}
//} else if (s == 2) {
//for(int i = (s + 1); i <= N; i++)  {
//double t = t0 + h * i;
//double y = sol.end()->second + h * (3.0 / 2.0 * rhs(sol.end()->first, sol.end()->second)
//                                    - 0.5 * rhs(std::prev(sol.end(), 1)->first, std::prev(sol.end(), 1)->second));
//sol.insert({t, y});
//}
//} else if (s == 3) {
//for(int i = (s + 1); i <= N; i++) {
//double t = t0 + h * i;
//double y = sol.end()->second + h * (23. / 12. * rhs(sol.end()->first, sol.end()->second)
//                                    - 16. / 12. * rhs(std::prev(sol.end(), 1)->first, std::prev(sol.end(), 1)->second)
//                                    + 5. / 12 * rhs(std::prev(sol.end(), 2)->first, std::prev(sol.end(), 2)->second));
//sol.insert({t, y});
//}
//} else if (s == 4) {
//for(int i = (s + 1); i <= N; i++) {
//double t = t0 + h * i;
//double y = sol.end()->second + h * (55. / 24. * rhs(sol.end()->first, sol.end()->second)
//                                    - 59. / 24. * rhs(std::prev(sol.end(), 1)->first, std::prev(sol.end(), 1)->second)
//                                    + 37. / 24 * rhs(std::prev(sol.end(), 2)->first, std::prev(sol.end(), 2)->second))
//           - 9. / 24. * rhs(std::prev(sol.end(), 3)->first, std::prev(sol.end(), 3)->second);
//sol.insert({t, y});
//}
//}
//}