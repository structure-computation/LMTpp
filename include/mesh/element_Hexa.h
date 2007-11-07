#ifndef LMT_HEXA
#define LMT_HEXA
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Hexa &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 33, 66, 99, 132, 269, 406, 543, 680, 817, }; // fonction de lordre du poly
    static const double values[] = {
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.0,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.0,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.0,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Hexa &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.25*nodes[0]->pos[1]; T reg1=0.25*nodes[1]->pos[1]; T reg2=0.25*nodes[0]->pos[2]; T reg3=0.25*nodes[1]->pos[2]; T reg4=0.25*nodes[2]->pos[1];
    T reg5=reg0+reg1; T reg6=reg2+reg3; T reg7=0.25*nodes[2]->pos[2]; reg0=reg1-reg0; reg2=reg3-reg2;
    reg1=reg4+reg5; reg3=reg7-reg6; T reg8=0.25*nodes[3]->pos[2]; reg6=reg6+reg7; reg0=reg4+reg0;
    T reg9=0.25*nodes[3]->pos[1]; reg5=reg4-reg5; reg2=reg7+reg2; reg4=0.25*nodes[1]->pos[0]; reg7=0.25*nodes[0]->pos[0];
    reg5=reg5+reg9; T reg10=0.25*nodes[4]->pos[1]; T reg11=0.25*nodes[4]->pos[2]; reg6=reg6+reg8; reg2=reg2-reg8;
    reg3=reg8+reg3; reg1=reg9+reg1; reg8=reg4+reg7; reg9=reg0-reg9; reg0=0.25*nodes[2]->pos[0];
    reg7=reg4-reg7; reg3=reg3-reg11; reg4=0.25*nodes[5]->pos[2]; reg6=reg11-reg6; reg1=reg10-reg1;
    reg11=reg2-reg11; reg9=reg9-reg10; reg2=reg0-reg8; T reg12=0.25*nodes[5]->pos[1]; reg10=reg5-reg10;
    reg5=0.25*nodes[3]->pos[0]; reg7=reg7+reg0; reg9=reg12+reg9; T reg13=0.25*nodes[4]->pos[0]; reg1=reg12+reg1;
    reg2=reg5+reg2; reg7=reg7-reg5; reg3=reg3-reg4; reg12=reg10-reg12; reg10=0.25*nodes[6]->pos[1];
    T reg14=0.25*nodes[6]->pos[2]; reg6=reg6+reg4; reg8=reg0+reg8; reg11=reg4+reg11; reg2=reg2-reg13;
    reg12=reg12+reg10; reg0=0.25*nodes[7]->pos[1]; reg9=reg10+reg9; reg1=reg10+reg1; reg11=reg14+reg11;
    reg7=reg7-reg13; reg3=reg14+reg3; reg4=0.25*nodes[5]->pos[0]; reg14=reg6+reg14; reg8=reg5+reg8;
    reg5=0.25*nodes[7]->pos[2]; reg9=reg9-reg0; reg11=reg11-reg5; reg8=reg13-reg8; reg6=0.25*nodes[6]->pos[0];
    reg2=reg2-reg4; reg7=reg7+reg4; reg1=reg0+reg1; reg3=reg5+reg3; reg0=reg12+reg0;
    reg5=reg14+reg5; reg7=reg7+reg6; reg10=reg1*reg11; reg12=0.25*nodes[7]->pos[0]; reg8=reg4+reg8;
    reg4=reg0*reg5; reg5=reg5*reg9; reg1=reg3*reg1; reg2=reg6+reg2; reg8=reg6+reg8;
    reg9=reg3*reg9; reg11=reg0*reg11; reg10=reg5-reg10; reg7=reg7-reg12; reg1=reg4-reg1;
    reg2=reg12+reg2; reg10=reg2*reg10; reg8=reg12+reg8; reg1=reg7*reg1; reg11=reg9-reg11;
    reg10=reg1-reg10; reg11=reg8*reg11; T det_jac=reg10+reg11;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1],nodes[4],nodes[7],nodes[6],nodes[5]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=1-var_inter[2]; T reg3=reg0*reg1; T reg4=reg0*reg2;
    T reg5=reg2*var_inter[0]; T reg6=reg1*var_inter[0]; T reg7=pos_nodes[0][0]*reg4; T reg8=pos_nodes[1][0]*reg5; T reg9=pos_nodes[0][0]*reg3;
    T reg10=reg6*pos_nodes[1][0]; T reg11=pos_nodes[1][2]*reg5; T reg12=pos_nodes[0][2]*reg4; T reg13=pos_nodes[0][1]*reg4; T reg14=reg3*pos_nodes[0][2];
    T reg15=reg6*pos_nodes[1][2]; T reg16=pos_nodes[1][1]*reg5; T reg17=reg3*pos_nodes[0][1]; T reg18=reg6*pos_nodes[1][1]; T reg19=var_inter[0]*var_inter[1];
    T reg20=reg19*pos_nodes[2][2]; reg15=reg14+reg15; reg14=pos_nodes[2][0]*reg5; reg8=reg7+reg8; reg10=reg9+reg10;
    reg7=reg19*pos_nodes[2][0]; reg11=reg12+reg11; reg9=reg0*var_inter[1]; reg12=pos_nodes[2][2]*reg5; T reg21=pos_nodes[2][1]*reg5;
    reg16=reg13+reg16; reg13=reg19*pos_nodes[2][1]; reg18=reg17+reg18; reg17=reg2*reg6; T reg22=reg3*reg2;
    T reg23=reg1*reg2; reg8=reg14-reg8; reg14=pos_nodes[3][0]*reg4; reg7=reg10+reg7; reg10=reg9*pos_nodes[3][0];
    T reg24=pos_nodes[3][2]*reg4; reg11=reg12-reg11; reg12=pos_nodes[0][0]*reg22; T reg25=reg17*pos_nodes[1][0]; T reg26=pos_nodes[1][1]*reg23;
    T reg27=pos_nodes[0][1]*reg23; T reg28=reg17*pos_nodes[1][1]; T reg29=reg22*pos_nodes[0][1]; T reg30=reg2*reg19; reg16=reg21-reg16;
    reg21=pos_nodes[3][1]*reg4; T reg31=reg9*pos_nodes[3][1]; reg13=reg18+reg13; reg18=reg2*var_inter[1]; T reg32=pos_nodes[0][0]*reg23;
    T reg33=reg0*var_inter[2]; reg20=reg15+reg20; reg15=pos_nodes[1][0]*reg23; T reg34=reg9*pos_nodes[3][2]; T reg35=reg17*pos_nodes[1][2];
    reg25=reg12+reg25; reg12=reg30*pos_nodes[2][0]; T reg36=pos_nodes[0][2]*reg23; T reg37=pos_nodes[1][2]*reg23; T reg38=reg3*pos_nodes[4][2];
    reg27=reg26-reg27; reg26=pos_nodes[2][1]*reg18; T reg39=reg30*pos_nodes[2][1]; reg28=reg29+reg28; reg34=reg20+reg34;
    reg20=pos_nodes[2][0]*reg18; reg21=reg16+reg21; reg16=pos_nodes[4][1]*reg33; reg31=reg13+reg31; reg32=reg15-reg32;
    reg13=reg3*pos_nodes[4][1]; reg15=reg3*pos_nodes[4][0]; reg2=reg2*reg9; reg24=reg11+reg24; reg11=reg22*pos_nodes[0][2];
    reg14=reg8+reg14; reg8=pos_nodes[4][0]*reg33; reg29=var_inter[0]*var_inter[2]; reg10=reg7+reg10; reg7=pos_nodes[4][2]*reg33;
    T reg40=reg6*pos_nodes[5][1]; reg31=reg13-reg31; reg13=pos_nodes[3][0]*reg18; reg7=reg24-reg7; reg20=reg32+reg20;
    reg24=pos_nodes[5][2]*reg29; reg32=pos_nodes[5][0]*reg29; reg16=reg21-reg16; reg21=pos_nodes[5][1]*reg29; reg8=reg14-reg8;
    reg14=reg30*pos_nodes[2][2]; reg34=reg38-reg34; reg38=reg1*var_inter[2]; T reg41=reg6*pos_nodes[5][2]; reg35=reg11+reg35;
    reg12=reg25+reg12; reg11=reg2*pos_nodes[3][0]; reg25=pos_nodes[2][2]*reg18; reg36=reg37-reg36; reg37=reg6*pos_nodes[5][0];
    reg10=reg15-reg10; reg15=reg3*var_inter[2]; reg39=reg28+reg39; reg28=pos_nodes[3][1]*reg18; reg26=reg27+reg26;
    reg27=reg2*pos_nodes[3][1]; reg41=reg34+reg41; reg24=reg7-reg24; reg7=reg19*pos_nodes[6][2]; reg40=reg31+reg40;
    reg25=reg36+reg25; reg31=pos_nodes[3][2]*reg18; reg34=reg19*pos_nodes[6][1]; reg36=reg15*pos_nodes[4][1]; reg27=reg39+reg27;
    reg39=reg2*pos_nodes[3][2]; reg14=reg35+reg14; reg35=pos_nodes[6][2]*reg29; T reg42=pos_nodes[4][0]*reg38; reg13=reg20-reg13;
    reg20=reg15*pos_nodes[4][0]; reg28=reg26-reg28; reg26=pos_nodes[4][1]*reg38; reg32=reg8-reg32; reg8=pos_nodes[6][0]*reg29;
    reg37=reg10+reg37; reg10=reg19*pos_nodes[6][0]; T reg43=pos_nodes[6][1]*reg29; reg21=reg16-reg21; reg11=reg12+reg11;
    reg12=reg6*var_inter[2]; reg16=pos_nodes[4][2]*reg38; T reg44=pos_nodes[7][0]*reg33; T reg45=reg9*pos_nodes[7][0]; T reg46=pos_nodes[7][2]*reg33;
    reg35=reg24+reg35; reg31=reg25-reg31; reg10=reg37+reg10; reg20=reg11+reg20; reg11=reg12*pos_nodes[5][0];
    reg24=pos_nodes[5][0]*reg38; reg42=reg13-reg42; reg8=reg32+reg8; reg13=pos_nodes[7][1]*reg33; reg43=reg21+reg43;
    reg21=reg15*pos_nodes[4][2]; reg39=reg14+reg39; reg34=reg40+reg34; reg14=reg9*pos_nodes[7][1]; reg25=reg19*var_inter[2];
    reg32=pos_nodes[5][1]*reg38; reg26=reg28-reg26; reg36=reg27+reg36; reg27=reg12*pos_nodes[5][1]; reg28=reg9*pos_nodes[7][2];
    reg7=reg41+reg7; reg37=var_inter[1]*var_inter[2]; reg40=pos_nodes[6][0]*reg37; reg46=reg35+reg46; reg35=reg9*var_inter[2];
    reg28=reg7+reg28; reg24=reg42+reg24; reg21=reg39+reg21; reg7=reg12*pos_nodes[5][2]; reg39=reg25*pos_nodes[6][1];
    reg27=reg36+reg27; reg32=reg26+reg32; reg14=reg34+reg14; reg26=pos_nodes[6][1]*reg37; reg34=reg25*pos_nodes[6][0];
    reg11=reg20+reg11; reg16=reg31-reg16; reg13=reg43+reg13; reg20=pos_nodes[5][2]*reg38; reg45=reg10+reg45;
    reg44=reg8+reg44; reg8=pos_nodes[7][1]*reg37; reg7=reg21+reg7; reg10=reg25*pos_nodes[6][2]; reg21=reg45*reg46;
    reg26=reg32+reg26; reg31=reg13*reg28; reg32=reg44*reg28; reg36=reg14*reg46; reg41=reg35*pos_nodes[7][0];
    reg39=reg27+reg39; reg27=reg35*pos_nodes[7][1]; reg34=reg11+reg34; reg40=reg24+reg40; reg11=pos_nodes[7][0]*reg37;
    reg20=reg16+reg20; reg16=pos_nodes[6][2]*reg37; reg36=reg31-reg36; reg24=reg44*reg14; reg42=pos_nodes[7][2]*reg37;
    reg16=reg20+reg16; reg11=reg40-reg11; reg21=reg32-reg21; reg20=reg45*reg13; reg40=reg35*pos_nodes[7][2];
    reg41=reg34+reg41; reg27=reg39+reg27; reg10=reg7+reg10; reg8=reg26-reg8; reg7=reg11*reg36;
    reg42=reg16-reg42; reg40=reg10+reg40; reg41=pos[0]-reg41; reg10=reg8*reg21; reg27=pos[1]-reg27;
    reg20=reg24-reg20; reg16=var_inter[0]*reg8; reg26=var_inter[0]*reg11; reg34=reg42*reg20; reg39=reg8*reg28;
    reg7=reg10-reg7; reg10=reg11*reg46; reg43=reg14*reg42; T reg47=reg8*reg46; T reg48=reg13*reg42;
    T reg49=reg11*reg28; T reg50=reg44*reg42; T reg51=reg45*reg42; reg40=pos[2]-reg40; T reg52=var_inter[1]*reg44;
    reg26=reg41+reg26; reg41=var_inter[0]*reg42; reg16=reg27+reg16; reg27=var_inter[1]*reg13; reg51=reg49-reg51;
    T reg53=var_inter[2]*reg45; reg48=reg47-reg48; reg50=reg10-reg50; T reg54=var_inter[2]*reg14; reg43=reg39-reg43;
    reg26=reg52+reg26; reg34=reg7-reg34; reg7=reg11*reg14; reg52=reg44*reg8; reg16=reg27+reg16;
    reg27=var_inter[1]*reg46; reg41=reg40+reg41; reg40=reg11*reg13; T reg55=reg45*reg8; reg52=reg40-reg52;
    reg50=reg50/reg34; reg55=reg7-reg55; reg26=reg53+reg26; reg53=var_inter[2]*reg28; reg16=reg54+reg16;
    reg41=reg27+reg41; reg36=reg36/reg34; reg43=reg43/reg34; reg48=reg48/reg34; reg21=reg21/reg34;
    reg51=reg51/reg34; reg41=reg53+reg41; reg20=reg20/reg34; reg55=reg55/reg34; reg34=reg52/reg34;
    reg36=reg26*reg36; reg21=reg16*reg21; reg50=reg16*reg50; reg43=reg26*reg43; reg51=reg16*reg51;
    reg48=reg26*reg48; reg48=reg50-reg48; reg34=reg41*reg34; reg51=reg43-reg51; reg55=reg41*reg55;
    reg36=reg21-reg36; reg20=reg41*reg20; var_inter[1]=reg55+reg51; var_inter[0]=reg36-reg20; var_inter[2]=reg48-reg34;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=1-var_inter[2]; T reg3=var_inter[0]*reg2; T reg4=reg0*reg2;
    T reg5=reg0*reg1; T reg6=var_inter[0]*reg1; T reg7=pos_nodes[0][2]*reg5; T reg8=pos_nodes[1][2]*reg6; T reg9=pos_nodes[0][0]*reg4;
    T reg10=pos_nodes[1][0]*reg3; T reg11=reg5*pos_nodes[0][0]; T reg12=pos_nodes[1][0]*reg6; T reg13=pos_nodes[1][2]*reg3; T reg14=pos_nodes[0][2]*reg4;
    T reg15=pos_nodes[0][1]*reg4; T reg16=pos_nodes[1][1]*reg3; T reg17=pos_nodes[0][1]*reg5; T reg18=pos_nodes[1][1]*reg6; T reg19=var_inter[0]*var_inter[1];
    reg10=reg9+reg10; reg9=pos_nodes[2][0]*reg3; T reg20=var_inter[1]*reg0; reg12=reg11+reg12; reg11=reg19*pos_nodes[2][0];
    reg8=reg7+reg8; reg7=reg19*pos_nodes[2][2]; reg13=reg14+reg13; reg14=pos_nodes[2][2]*reg3; T reg21=pos_nodes[2][1]*reg3;
    T reg22=reg1*reg2; T reg23=reg6*reg2; reg18=reg17+reg18; reg17=reg19*pos_nodes[2][1]; T reg24=reg5*reg2;
    reg16=reg15+reg16; reg10=reg9-reg10; reg9=pos_nodes[3][0]*reg4; reg16=reg21-reg16; reg11=reg12+reg11;
    reg12=reg20*pos_nodes[3][0]; reg15=pos_nodes[3][2]*reg4; reg21=pos_nodes[0][1]*reg24; T reg25=pos_nodes[1][1]*reg23; reg13=reg14-reg13;
    reg17=reg18+reg17; reg14=reg19*reg2; reg18=reg20*pos_nodes[3][1]; T reg26=reg24*pos_nodes[0][0]; T reg27=pos_nodes[1][0]*reg23;
    T reg28=pos_nodes[3][1]*reg4; T reg29=pos_nodes[1][1]*reg22; T reg30=pos_nodes[0][1]*reg22; T reg31=pos_nodes[1][0]*reg22; T reg32=pos_nodes[0][0]*reg22;
    T reg33=var_inter[1]*reg2; T reg34=reg20*pos_nodes[3][2]; reg7=reg8+reg7; reg8=var_inter[2]*reg0; T reg35=pos_nodes[1][2]*reg23;
    reg9=reg10+reg9; reg34=reg7+reg34; reg7=pos_nodes[0][2]*reg24; reg10=pos_nodes[2][0]*reg33; reg27=reg26+reg27;
    reg26=reg14*pos_nodes[2][0]; T reg36=var_inter[0]*var_inter[2]; reg32=reg31-reg32; reg25=reg21+reg25; reg21=pos_nodes[0][2]*reg22;
    reg31=pos_nodes[1][2]*reg22; T reg37=reg14*pos_nodes[2][1]; reg30=reg29-reg30; reg29=pos_nodes[2][1]*reg33; T reg38=pos_nodes[4][2]*reg8;
    reg15=reg13+reg15; reg13=reg5*pos_nodes[4][0]; reg2=reg20*reg2; reg18=reg17+reg18; reg17=pos_nodes[4][1]*reg5;
    T reg39=pos_nodes[4][2]*reg5; T reg40=pos_nodes[4][1]*reg8; reg12=reg11+reg12; reg28=reg16+reg28; reg11=pos_nodes[4][0]*reg8;
    reg16=pos_nodes[3][1]*reg33; reg37=reg25+reg37; reg34=reg39-reg34; reg25=var_inter[2]*reg1; reg39=reg6*pos_nodes[5][1];
    reg18=reg17-reg18; reg17=pos_nodes[5][1]*reg36; reg40=reg28-reg40; reg28=reg6*pos_nodes[5][2]; T reg41=var_inter[2]*reg5;
    reg11=reg9-reg11; reg9=pos_nodes[5][0]*reg36; T reg42=pos_nodes[5][2]*reg36; reg38=reg15-reg38; reg15=reg14*pos_nodes[2][2];
    reg35=reg7+reg35; reg12=reg13-reg12; reg7=reg6*pos_nodes[5][0]; reg13=pos_nodes[3][0]*reg33; reg10=reg32+reg10;
    reg29=reg30+reg29; reg30=reg2*pos_nodes[3][1]; reg21=reg31-reg21; reg31=pos_nodes[2][2]*reg33; reg32=reg2*pos_nodes[3][0];
    reg26=reg27+reg26; reg27=pos_nodes[3][2]*reg33; reg39=reg18+reg39; reg18=reg19*pos_nodes[6][1]; reg31=reg21+reg31;
    reg21=pos_nodes[6][2]*reg36; T reg43=reg19*pos_nodes[6][2]; reg15=reg35+reg15; reg28=reg34+reg28; reg34=pos_nodes[4][1]*reg41;
    reg42=reg38-reg42; reg30=reg37+reg30; reg35=reg2*pos_nodes[3][2]; reg37=pos_nodes[4][0]*reg25; reg13=reg10-reg13;
    reg10=reg41*pos_nodes[4][0]; reg16=reg29-reg16; reg29=pos_nodes[4][1]*reg25; reg9=reg11-reg9; reg11=pos_nodes[6][0]*reg36;
    reg7=reg12+reg7; reg12=reg19*pos_nodes[6][0]; reg38=pos_nodes[6][1]*reg36; reg17=reg40-reg17; reg32=reg26+reg32;
    reg26=var_inter[2]*reg6; reg40=pos_nodes[4][2]*reg25; T reg44=pos_nodes[7][0]*reg8; T reg45=reg20*pos_nodes[7][0]; T reg46=pos_nodes[7][2]*reg8;
    reg21=reg42+reg21; reg27=reg31-reg27; reg12=reg7+reg12; reg10=reg32+reg10; reg7=reg26*pos_nodes[5][0];
    reg31=pos_nodes[5][0]*reg25; reg37=reg13-reg37; reg11=reg9+reg11; reg9=pos_nodes[7][1]*reg8; reg38=reg17+reg38;
    reg13=pos_nodes[4][2]*reg41; reg35=reg15+reg35; reg18=reg39+reg18; reg15=reg20*pos_nodes[7][1]; reg17=var_inter[2]*reg19;
    reg32=pos_nodes[5][1]*reg25; reg29=reg16-reg29; reg34=reg30+reg34; reg16=reg26*pos_nodes[5][1]; reg30=reg20*pos_nodes[7][2];
    reg43=reg28+reg43; reg28=var_inter[1]*var_inter[2]; reg39=pos_nodes[6][0]*reg28; reg46=reg21+reg46; reg21=var_inter[2]*reg20;
    reg30=reg43+reg30; reg31=reg37+reg31; reg13=reg35+reg13; reg35=reg26*pos_nodes[5][2]; reg37=reg17*pos_nodes[6][1];
    reg16=reg34+reg16; reg32=reg29+reg32; reg15=reg18+reg15; reg18=pos_nodes[6][1]*reg28; reg29=reg17*pos_nodes[6][0];
    reg7=reg10+reg7; reg40=reg27-reg40; reg9=reg38+reg9; reg10=pos_nodes[5][2]*reg25; reg45=reg12+reg45;
    reg44=reg11+reg44; reg11=pos_nodes[7][1]*reg28; reg35=reg13+reg35; reg12=reg17*pos_nodes[6][2]; reg13=reg45*reg46;
    reg18=reg32+reg18; reg27=reg9*reg30; reg32=reg44*reg30; reg34=reg15*reg46; reg38=reg21*pos_nodes[7][0];
    reg37=reg16+reg37; reg16=reg21*pos_nodes[7][1]; reg29=reg7+reg29; reg39=reg31+reg39; reg7=pos_nodes[7][0]*reg28;
    reg10=reg40+reg10; reg31=pos_nodes[6][2]*reg28; reg34=reg27-reg34; reg40=reg44*reg15; reg42=pos_nodes[7][2]*reg28;
    reg31=reg10+reg31; reg7=reg39-reg7; reg13=reg32-reg13; reg10=reg45*reg9; reg39=reg21*pos_nodes[7][2];
    reg38=reg29+reg38; reg16=reg37+reg16; reg12=reg35+reg12; reg11=reg18-reg11; reg18=reg7*reg34;
    reg42=reg31-reg42; reg39=reg12+reg39; reg38=pos[0]-reg38; reg12=reg11*reg13; reg16=pos[1]-reg16;
    reg10=reg40-reg10; reg29=var_inter[0]*reg11; reg31=var_inter[0]*reg7; reg35=reg42*reg10; reg37=reg11*reg30;
    reg18=reg12-reg18; reg12=reg7*reg46; reg43=reg15*reg42; T reg47=reg11*reg46; T reg48=reg9*reg42;
    T reg49=reg7*reg30; T reg50=reg44*reg42; T reg51=reg45*reg42; reg39=pos[2]-reg39; T reg52=var_inter[1]*reg44;
    reg31=reg38+reg31; reg38=var_inter[0]*reg42; reg29=reg16+reg29; reg16=var_inter[1]*reg9; reg51=reg49-reg51;
    T reg53=var_inter[2]*reg45; reg48=reg47-reg48; reg50=reg12-reg50; T reg54=var_inter[2]*reg15; reg43=reg37-reg43;
    reg31=reg52+reg31; reg35=reg18-reg35; reg18=reg7*reg15; reg52=reg44*reg11; reg29=reg16+reg29;
    reg16=var_inter[1]*reg46; reg38=reg39+reg38; reg39=reg7*reg9; T reg55=reg45*reg11; reg52=reg39-reg52;
    reg50=reg50/reg35; reg55=reg18-reg55; reg31=reg53+reg31; reg53=var_inter[2]*reg30; reg29=reg54+reg29;
    reg38=reg16+reg38; reg34=reg34/reg35; reg43=reg43/reg35; reg48=reg48/reg35; reg13=reg13/reg35;
    reg51=reg51/reg35; reg38=reg53+reg38; reg10=reg10/reg35; reg55=reg55/reg35; reg35=reg52/reg35;
    reg34=reg31*reg34; reg13=reg29*reg13; reg50=reg29*reg50; reg43=reg31*reg43; reg51=reg29*reg51;
    reg48=reg31*reg48; reg48=reg50-reg48; reg35=reg38*reg35; reg51=reg43-reg51; reg55=reg38*reg55;
    reg34=reg13-reg34; reg10=reg38*reg10; var_inter[1]+=reg55+reg51; var_inter[0]+=reg34-reg10; var_inter[2]+=reg48-reg35;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=var_inter[0]*reg1; reg1=reg0*reg1; T reg3=1-var_inter[2];
    T reg4=reg3*reg2; T reg5=reg1*reg3; T reg6=var_inter[0]*var_inter[1]; reg4=val[1]*reg4; reg5=val[0]*reg5;
    T reg7=reg3*reg6; reg0=var_inter[1]*reg0; reg7=val[2]*reg7; reg3=reg3*reg0; reg4=reg5+reg4;
    reg1=var_inter[2]*reg1; reg7=reg4+reg7; reg3=val[3]*reg3; reg2=var_inter[2]*reg2; reg1=val[4]*reg1;
    reg3=reg7+reg3; reg1=reg3+reg1; reg2=val[5]*reg2; reg6=var_inter[2]*reg6; reg2=reg1+reg2;
    reg6=val[6]*reg6; reg0=var_inter[2]*reg0; reg6=reg2+reg6; reg0=val[7]*reg0; res=reg6+reg0;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Hexa &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Hexa> {
    static const unsigned nb_permutations = 23;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[7],e.nodes[6],e.nodes[5],e.nodes[0],e.nodes[3],e.nodes[2],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[2],e.nodes[6],e.nodes[7],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[1],e.nodes[3],e.nodes[7],e.nodes[6],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[5],e.nodes[6],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[7],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[0],e.nodes[3],e.nodes[7],e.nodes[4],e.nodes[1],e.nodes[2],e.nodes[6],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 5 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[5],e.nodes[6],e.nodes[7],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 6 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[6],e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 7 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[6],e.nodes[7],e.nodes[3],e.nodes[1],e.nodes[5],e.nodes[4],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 8 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[7],e.nodes[6],e.nodes[2],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 9 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[6],e.nodes[2],e.nodes[1],e.nodes[4],e.nodes[7],e.nodes[3],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 10 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[7],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[6],e.nodes[5],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 11 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[6],e.nodes[7],e.nodes[4],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 12 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[5],e.nodes[4],e.nodes[7],e.nodes[2],e.nodes[1],e.nodes[0],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 13 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[7],e.nodes[3],e.nodes[2],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 14 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[4],e.nodes[6],e.nodes[2],e.nodes[3],e.nodes[7]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 15 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[2],e.nodes[1],e.nodes[5],e.nodes[7],e.nodes[3],e.nodes[0],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 16 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[4],e.nodes[0],e.nodes[3],e.nodes[6],e.nodes[5],e.nodes[1],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 17 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[2],e.nodes[7],e.nodes[4],e.nodes[5],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 18 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[7],e.nodes[6],e.nodes[1],e.nodes[0],e.nodes[3],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 19 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[3],e.nodes[2],e.nodes[6],e.nodes[4],e.nodes[0],e.nodes[1],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 20 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[2],e.nodes[3],e.nodes[7],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 21 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[1],e.nodes[5],e.nodes[6],e.nodes[3],e.nodes[0],e.nodes[4],e.nodes[7]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 22 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[0],e.nodes[3],e.nodes[7],e.nodes[5],e.nodes[1],e.nodes[2],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[7],e.nodes[6],e.nodes[5],e.nodes[0],e.nodes[3],e.nodes[2],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[7],e.nodes[6],e.nodes[2],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[0],e.nodes[3],e.nodes[7],e.nodes[4],e.nodes[1],e.nodes[2],e.nodes[6],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[0],e.nodes[3],e.nodes[7],e.nodes[5],e.nodes[1],e.nodes[2],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[1],e.nodes[3],e.nodes[7],e.nodes[6],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 5 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[2],e.nodes[7],e.nodes[4],e.nodes[5],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 6 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[6],e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 7 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[4],e.nodes[0],e.nodes[3],e.nodes[6],e.nodes[5],e.nodes[1],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 8 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[2],e.nodes[6],e.nodes[7],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 9 ) {
            typename TE::TNode *tmp[] = {e.nodes[7],e.nodes[3],e.nodes[2],e.nodes[6],e.nodes[4],e.nodes[0],e.nodes[1],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 10 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[7],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[6],e.nodes[5],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 11 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[6],e.nodes[7],e.nodes[4],e.nodes[5]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 12 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[5],e.nodes[4],e.nodes[7],e.nodes[2],e.nodes[1],e.nodes[0],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 13 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[7],e.nodes[3],e.nodes[2],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[1]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 14 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[1],e.nodes[5],e.nodes[6],e.nodes[3],e.nodes[0],e.nodes[4],e.nodes[7]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 15 ) {
            typename TE::TNode *tmp[] = {e.nodes[6],e.nodes[2],e.nodes[1],e.nodes[5],e.nodes[7],e.nodes[3],e.nodes[0],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 16 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[6],e.nodes[7],e.nodes[3],e.nodes[1],e.nodes[5],e.nodes[4],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 17 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[5],e.nodes[6],e.nodes[7],e.nodes[4]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 18 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[7],e.nodes[6],e.nodes[1],e.nodes[0],e.nodes[3],e.nodes[2]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 19 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[6],e.nodes[2],e.nodes[1],e.nodes[4],e.nodes[7],e.nodes[3],e.nodes[0]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 20 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[2],e.nodes[3],e.nodes[7],e.nodes[6]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 21 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[4],e.nodes[6],e.nodes[2],e.nodes[3],e.nodes[7]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 22 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[5],e.nodes[6],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[7],e.nodes[3]};
            for(unsigned i=0;i<8;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
};

}
#endif // LMT_HEXA
