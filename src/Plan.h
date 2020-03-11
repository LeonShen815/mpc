#ifndef SRC_PLAN_H
#define SRC_PLAN_H

// Ahh I copied all these from the planner repo to make things easier but they should really be in their own library

#include <vector>
#include <path_planner/State.h>
#include "DubinsWrapper.h"

class Plan {
public:
    Plan() = default;

    Plan(const State& s1, const State& s2, double rho);

//    void append(const State& s); // no

    void append(const Plan& plan);

    void append(const DubinsWrapper& dubinsPath);

    void sample(State& s) const;

    bool empty() const;

    double totalTime() const;

    std::vector<State> getHalfSecondSamples() const;

    const std::vector<DubinsWrapper>& get() const;

//    std::vector<State> get() const; // no

//    std::string toString() const;

    static constexpr double timeHorizon() { return c_TimeHorizon; }

    static constexpr double timeMinimum() { return c_TimeMinimum; }

    static constexpr double planTimeDensity() { return c_PlanTimeDensity; }
private:
    std::vector<DubinsWrapper> m_DubinsPaths;

//    std::vector<State> m_States;

    static constexpr double c_TimeHorizon = 30;
    static constexpr double c_TimeMinimum = 5;
    static constexpr double c_PlanTimeDensity = 0.5;
};


#endif //SRC_PLAN_H