//
// Created by ashish on 1/17/22.
//

#ifndef BT_UTKARSH_IO_TEST_H
#define BT_UTKARSH_IO_TEST_H
#include <array>
#include <vector>
#include <iostream>
struct volModelCurveStrike{
    int token;
    double iv;
    double modelIV;
    double biasIV;
    double nbiasIV;
    double delta;
    double vega;
    bool valid;
    volModelCurveStrike():token(0),iv(0),modelIV(0),biasIV(0),nbiasIV(0),delta(0),vega(0),valid(false){

    }
};
struct volModelCurve{
    uint64_t time;
    double rho;
    double eta;
    double atmiv;
    std::array<volModelCurveStrike,512> arrayOfVolStrikes;
};

void print(volModelCurve *t){
    std::cout << t->time<<","<<t->rho<<","<<t->eta<<std::endl;
}
#endif //BT_UTKARSH_IO_TEST_H
