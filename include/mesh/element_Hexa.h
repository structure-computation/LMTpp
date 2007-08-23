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
    reg1=reg7-reg6; reg3=0.25*nodes[3]->pos[2]; reg6=reg6+reg7; T reg8=reg4+reg5; T reg9=0.25*nodes[3]->pos[1];
    reg5=reg4-reg5; reg0=reg4+reg0; reg2=reg7+reg2; reg4=0.25*nodes[1]->pos[0]; reg7=0.25*nodes[0]->pos[0];
    reg2=reg2-reg3; reg1=reg3+reg1; T reg10=0.25*nodes[4]->pos[1]; reg5=reg5+reg9; reg8=reg9+reg8;
    T reg11=0.25*nodes[4]->pos[2]; T reg12=reg4-reg7; T reg13=0.25*nodes[2]->pos[0]; reg3=reg6+reg3; reg7=reg4+reg7;
    reg9=reg0-reg9; reg3=reg11-reg3; reg0=0.25*nodes[5]->pos[2]; reg2=reg2-reg11; reg4=0.25*nodes[3]->pos[0];
    reg11=reg1-reg11; reg8=reg10-reg8; reg1=reg13-reg7; reg9=reg9-reg10; reg12=reg12+reg13;
    reg10=reg5-reg10; reg5=0.25*nodes[5]->pos[1]; reg1=reg4+reg1; reg7=reg13+reg7; reg9=reg5+reg9;
    reg8=reg5+reg8; reg6=0.25*nodes[4]->pos[0]; reg11=reg11-reg0; reg5=reg10-reg5; reg10=0.25*nodes[6]->pos[1];
    reg12=reg12-reg4; reg13=0.25*nodes[6]->pos[2]; reg3=reg3+reg0; reg2=reg0+reg2; reg0=0.25*nodes[5]->pos[0];
    reg7=reg4+reg7; reg1=reg1-reg6; reg9=reg10+reg9; reg2=reg13+reg2; reg8=reg10+reg8;
    reg12=reg12-reg6; reg4=0.25*nodes[7]->pos[1]; reg11=reg13+reg11; reg13=reg3+reg13; reg3=0.25*nodes[7]->pos[2];
    reg10=reg5+reg10; reg9=reg9-reg4; reg2=reg2-reg3; reg7=reg6-reg7; reg5=0.25*nodes[6]->pos[0];
    reg1=reg1-reg0; reg12=reg12+reg0; reg8=reg4+reg8; reg11=reg3+reg11; reg4=reg10+reg4;
    reg3=reg13+reg3; reg12=reg12+reg5; reg6=reg8*reg2; reg10=0.25*nodes[7]->pos[0]; reg7=reg0+reg7;
    reg0=reg4*reg3; reg3=reg3*reg9; reg8=reg11*reg8; reg1=reg5+reg1; reg7=reg5+reg7;
    reg9=reg11*reg9; reg2=reg4*reg2; reg6=reg3-reg6; reg12=reg12-reg10; reg8=reg0-reg8;
    reg1=reg10+reg1; reg6=reg1*reg6; reg7=reg10+reg7; reg8=reg12*reg8; reg2=reg9-reg2;
    reg6=reg8-reg6; reg2=reg7*reg2; T det_jac=reg6+reg2;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1],nodes[4],nodes[7],nodes[6],nodes[5]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=1-var_inter[2]; T reg3=reg0*reg2; T reg4=reg2*var_inter[0];
    T reg5=reg0*reg1; T reg6=reg1*var_inter[0]; T reg7=reg6*pos_nodes[1][0]; T reg8=pos_nodes[1][1]*reg4; T reg9=pos_nodes[0][1]*reg3;
    T reg10=pos_nodes[0][0]*reg5; T reg11=reg5*pos_nodes[0][1]; T reg12=reg5*pos_nodes[0][2]; T reg13=reg6*pos_nodes[1][2]; T reg14=var_inter[0]*var_inter[1];
    T reg15=reg6*pos_nodes[1][1]; T reg16=pos_nodes[1][0]*reg4; T reg17=pos_nodes[0][0]*reg3; T reg18=pos_nodes[1][2]*reg4; T reg19=pos_nodes[0][2]*reg3;
    reg16=reg17+reg16; reg17=pos_nodes[2][0]*reg4; reg7=reg10+reg7; reg10=reg14*pos_nodes[2][0]; T reg20=pos_nodes[2][1]*reg4;
    reg9=reg8+reg9; reg15=reg11+reg15; reg13=reg12+reg13; reg18=reg19+reg18; reg8=reg14*pos_nodes[2][1];
    reg11=reg14*pos_nodes[2][2]; reg12=pos_nodes[2][2]*reg4; reg19=reg5*reg2; T reg21=reg2*reg6; T reg22=reg1*reg2;
    T reg23=reg0*var_inter[1]; T reg24=pos_nodes[1][0]*reg22; T reg25=reg2*var_inter[1]; reg9=reg20-reg9; reg20=reg21*pos_nodes[1][1];
    T reg26=reg21*pos_nodes[1][0]; T reg27=reg23*pos_nodes[3][1]; reg10=reg7+reg10; reg7=reg23*pos_nodes[3][0]; reg8=reg15+reg8;
    reg15=pos_nodes[0][0]*reg19; T reg28=reg19*pos_nodes[0][1]; T reg29=reg3*pos_nodes[3][1]; T reg30=pos_nodes[0][1]*reg22; T reg31=pos_nodes[1][1]*reg22;
    T reg32=reg23*pos_nodes[3][2]; reg11=reg13+reg11; reg13=pos_nodes[0][0]*reg22; T reg33=reg3*pos_nodes[3][0]; reg16=reg17-reg16;
    reg18=reg12-reg18; reg12=reg3*pos_nodes[3][2]; reg17=reg2*reg14; T reg34=reg0*var_inter[2]; reg30=reg31-reg30;
    reg31=pos_nodes[2][1]*reg25; reg13=reg24-reg13; reg29=reg9+reg29; reg9=reg34*pos_nodes[4][1]; reg24=reg5*pos_nodes[4][1];
    reg27=reg8+reg27; reg20=reg28+reg20; reg8=reg17*pos_nodes[2][1]; reg28=reg21*pos_nodes[1][2]; T reg35=reg19*pos_nodes[0][2];
    T reg36=pos_nodes[1][2]*reg22; T reg37=pos_nodes[0][2]*reg22; reg32=reg11+reg32; reg2=reg2*reg23; reg12=reg18+reg12;
    reg11=reg34*pos_nodes[4][2]; reg18=reg5*pos_nodes[4][2]; T reg38=var_inter[0]*var_inter[2]; reg33=reg16+reg33; reg16=reg34*pos_nodes[4][0];
    T reg39=reg5*pos_nodes[4][0]; reg7=reg10+reg7; reg26=reg15+reg26; reg10=reg17*pos_nodes[2][0]; reg15=pos_nodes[2][0]*reg25;
    T reg40=reg6*pos_nodes[5][0]; reg7=reg39-reg7; reg31=reg30+reg31; reg15=reg13+reg15; reg13=reg25*pos_nodes[3][0];
    reg27=reg24-reg27; reg24=reg6*pos_nodes[5][1]; reg28=reg35+reg28; reg30=reg2*pos_nodes[3][0]; reg8=reg20+reg8;
    reg20=reg2*pos_nodes[3][1]; reg37=reg36-reg37; reg35=pos_nodes[2][2]*reg25; reg36=reg6*pos_nodes[5][2]; reg32=reg18-reg32;
    reg18=reg38*pos_nodes[5][0]; reg16=reg33-reg16; reg33=reg5*var_inter[2]; reg11=reg12-reg11; reg12=reg38*pos_nodes[5][2];
    reg39=reg17*pos_nodes[2][2]; T reg41=reg25*pos_nodes[3][1]; reg9=reg29-reg9; reg10=reg26+reg10; reg26=reg38*pos_nodes[5][1];
    reg29=reg1*var_inter[2]; reg30=reg10+reg30; reg10=reg14*pos_nodes[6][2]; T reg42=reg38*pos_nodes[6][0]; reg41=reg31-reg41;
    reg35=reg37+reg35; reg31=reg25*pos_nodes[3][2]; reg36=reg32+reg36; reg18=reg16-reg18; reg39=reg28+reg39;
    reg16=reg6*var_inter[2]; reg28=reg2*pos_nodes[3][2]; reg32=reg33*pos_nodes[4][0]; reg12=reg11-reg12; reg11=reg38*pos_nodes[6][2];
    reg37=reg29*pos_nodes[4][1]; reg40=reg7+reg40; reg7=reg38*pos_nodes[6][1]; reg26=reg9-reg26; reg24=reg27+reg24;
    reg9=reg14*pos_nodes[6][1]; reg13=reg15-reg13; reg15=reg29*pos_nodes[4][0]; reg27=reg14*pos_nodes[6][0]; T reg43=reg33*pos_nodes[4][1];
    reg20=reg8+reg20; reg27=reg40+reg27; reg8=reg16*pos_nodes[5][0]; reg37=reg41-reg37; reg40=pos_nodes[7][2]*reg34;
    reg11=reg12+reg11; reg43=reg20+reg43; reg12=reg16*pos_nodes[5][1]; reg20=reg29*pos_nodes[5][1]; reg41=reg33*pos_nodes[4][2];
    reg28=reg39+reg28; reg39=reg29*pos_nodes[5][0]; reg15=reg13-reg15; reg32=reg30+reg32; reg42=reg18+reg42;
    reg13=pos_nodes[7][1]*reg34; reg7=reg26+reg7; reg18=reg14*var_inter[2]; reg26=reg34*pos_nodes[7][0]; reg30=reg23*pos_nodes[7][2];
    T reg44=var_inter[1]*var_inter[2]; reg10=reg36+reg10; reg9=reg24+reg9; reg24=reg29*pos_nodes[4][2]; reg31=reg35-reg31;
    reg35=reg23*pos_nodes[7][1]; reg36=reg23*pos_nodes[7][0]; reg30=reg10+reg30; reg41=reg28+reg41; reg10=reg16*pos_nodes[5][2];
    reg28=reg44*pos_nodes[6][1]; reg20=reg37+reg20; reg13=reg7+reg13; reg35=reg9+reg35; reg12=reg43+reg12;
    reg7=reg18*pos_nodes[6][1]; reg26=reg42+reg26; reg36=reg27+reg36; reg24=reg31-reg24; reg9=reg29*pos_nodes[5][2];
    reg8=reg32+reg8; reg27=reg18*pos_nodes[6][0]; reg40=reg11+reg40; reg11=reg44*pos_nodes[6][0]; reg39=reg15+reg39;
    reg15=reg23*var_inter[2]; reg27=reg8+reg27; reg8=reg15*pos_nodes[7][0]; reg31=reg36*reg40; reg32=reg18*pos_nodes[6][2];
    reg10=reg41+reg10; reg37=reg26*reg30; reg41=reg35*reg40; reg42=reg13*reg30; reg28=reg20+reg28;
    reg20=pos_nodes[7][1]*reg44; reg7=reg12+reg7; reg12=reg15*pos_nodes[7][1]; reg11=reg39+reg11; reg39=reg44*pos_nodes[7][0];
    reg9=reg24+reg9; reg24=reg44*pos_nodes[6][2]; reg41=reg42-reg41; reg43=reg26*reg35; reg31=reg37-reg31;
    T reg45=reg36*reg13; reg8=reg27+reg8; reg27=pos_nodes[7][2]*reg44; reg24=reg9+reg24; reg12=reg7+reg12;
    reg7=reg15*pos_nodes[7][2]; reg32=reg10+reg32; reg39=reg11-reg39; reg20=reg28-reg20; reg45=reg43-reg45;
    reg9=reg20*reg31; reg10=reg39*reg41; reg27=reg24-reg27; reg12=pos[1]-reg12; reg8=pos[0]-reg8;
    reg7=reg32+reg7; reg11=var_inter[0]*reg39; reg24=var_inter[0]*reg20; reg28=reg26*reg27; reg32=reg13*reg27;
    reg11=reg8+reg11; reg8=var_inter[1]*reg26; T reg46=reg20*reg40; T reg47=reg35*reg27; T reg48=reg20*reg30;
    reg7=pos[2]-reg7; T reg49=reg27*reg45; reg10=reg9-reg10; reg9=var_inter[1]*reg13; reg24=reg12+reg24;
    reg12=var_inter[0]*reg27; T reg50=reg39*reg30; T reg51=reg36*reg27; T reg52=reg39*reg40; T reg53=reg36*reg20;
    T reg54=reg39*reg13; T reg55=reg39*reg35; T reg56=reg26*reg20; T reg57=var_inter[2]*reg35; T reg58=var_inter[2]*reg36;
    reg51=reg50-reg51; reg28=reg52-reg28; reg12=reg7+reg12; reg47=reg48-reg47; reg32=reg46-reg32;
    reg7=var_inter[1]*reg40; reg49=reg10-reg49; reg24=reg9+reg24; reg11=reg8+reg11; reg32=reg32/reg49;
    reg47=reg47/reg49; reg41=reg41/reg49; reg11=reg58+reg11; reg8=var_inter[2]*reg30; reg24=reg57+reg24;
    reg31=reg31/reg49; reg12=reg7+reg12; reg51=reg51/reg49; reg28=reg28/reg49; reg53=reg55-reg53;
    reg56=reg54-reg56; reg32=reg11*reg32; reg45=reg45/reg49; reg28=reg24*reg28; reg12=reg8+reg12;
    reg53=reg53/reg49; reg49=reg56/reg49; reg51=reg51*reg24; reg47=reg11*reg47; reg41=reg11*reg41;
    reg31=reg31*reg24; reg45=reg12*reg45; reg41=reg31-reg41; reg53=reg12*reg53; reg51=reg47-reg51;
    reg32=reg28-reg32; reg49=reg12*reg49; var_inter[0]=reg41-reg45; var_inter[2]=reg32-reg49; var_inter[1]=reg53+reg51;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[2]; T reg1=1-var_inter[0]; T reg2=1-var_inter[1]; T reg3=reg1*reg0; T reg4=var_inter[0]*reg0;
    T reg5=var_inter[0]*reg2; T reg6=reg1*reg2; T reg7=pos_nodes[0][0]*reg6; T reg8=pos_nodes[1][1]*reg5; T reg9=pos_nodes[0][1]*reg6;
    T reg10=pos_nodes[1][0]*reg5; T reg11=pos_nodes[0][1]*reg3; T reg12=reg3*pos_nodes[0][0]; T reg13=pos_nodes[1][2]*reg4; T reg14=pos_nodes[0][2]*reg3;
    T reg15=pos_nodes[1][0]*reg4; T reg16=var_inter[0]*var_inter[1]; T reg17=pos_nodes[1][1]*reg4; T reg18=pos_nodes[1][2]*reg5; T reg19=pos_nodes[0][2]*reg6;
    reg7=reg10+reg7; reg12=reg15+reg12; reg10=pos_nodes[2][0]*reg4; reg15=reg6*reg0; T reg20=pos_nodes[2][0]*reg16;
    T reg21=pos_nodes[2][1]*reg4; reg11=reg17+reg11; reg9=reg8+reg9; reg8=pos_nodes[2][1]*reg16; reg17=pos_nodes[2][2]*reg4;
    reg14=reg13+reg14; reg13=reg5*reg0; reg19=reg18+reg19; reg18=pos_nodes[2][2]*reg16; T reg22=var_inter[1]*reg1;
    T reg23=reg2*reg0; reg12=reg10-reg12; reg10=pos_nodes[0][1]*reg23; T reg24=pos_nodes[1][1]*reg23; T reg25=pos_nodes[3][1]*reg22;
    reg11=reg21-reg11; reg21=pos_nodes[3][0]*reg22; T reg26=pos_nodes[3][2]*reg22; T reg27=var_inter[1]*reg0; reg20=reg7+reg20;
    reg7=pos_nodes[0][0]*reg15; reg18=reg19+reg18; reg19=pos_nodes[1][0]*reg13; T reg28=pos_nodes[1][1]*reg13; T reg29=reg16*reg0;
    T reg30=pos_nodes[0][1]*reg15; reg8=reg9+reg8; reg14=reg17-reg14; reg9=var_inter[2]*reg1; reg17=pos_nodes[3][0]*reg3;
    T reg31=pos_nodes[3][2]*reg3; T reg32=pos_nodes[3][1]*reg3; T reg33=reg23*pos_nodes[0][0]; T reg34=pos_nodes[1][0]*reg23; T reg35=pos_nodes[2][1]*reg27;
    reg10=reg24-reg10; reg7=reg19+reg7; reg19=pos_nodes[2][0]*reg29; reg24=pos_nodes[4][1]*reg9; reg11=reg32+reg11;
    reg14=reg31+reg14; reg31=pos_nodes[4][2]*reg9; reg32=pos_nodes[0][2]*reg23; T reg36=pos_nodes[4][2]*reg6; T reg37=pos_nodes[1][2]*reg23;
    T reg38=pos_nodes[4][0]*reg9; reg12=reg17+reg12; reg17=pos_nodes[0][2]*reg15; reg33=reg34-reg33; reg34=pos_nodes[2][0]*reg27;
    T reg39=pos_nodes[1][2]*reg13; T reg40=pos_nodes[4][1]*reg6; T reg41=var_inter[0]*var_inter[2]; T reg42=pos_nodes[4][0]*reg6; reg30=reg28+reg30;
    reg28=pos_nodes[2][1]*reg29; reg20=reg21+reg20; reg8=reg25+reg8; reg18=reg26+reg18; reg0=reg22*reg0;
    reg8=reg40-reg8; reg21=pos_nodes[3][1]*reg0; reg25=pos_nodes[2][2]*reg27; reg32=reg37-reg32; reg26=pos_nodes[5][1]*reg5;
    reg28=reg30+reg28; reg30=pos_nodes[5][1]*reg41; reg24=reg11-reg24; reg11=pos_nodes[3][0]*reg27; reg34=reg33+reg34;
    reg33=pos_nodes[2][2]*reg29; reg38=reg12-reg38; reg12=pos_nodes[5][0]*reg41; reg17=reg39+reg17; reg37=pos_nodes[5][0]*reg5;
    reg39=var_inter[2]*reg2; reg20=reg42-reg20; reg18=reg36-reg18; reg36=pos_nodes[3][0]*reg0; reg40=pos_nodes[3][1]*reg27;
    reg35=reg10+reg35; reg31=reg14-reg31; reg10=pos_nodes[5][2]*reg41; reg14=pos_nodes[5][2]*reg5; reg42=var_inter[2]*reg6;
    reg19=reg7+reg19; reg7=pos_nodes[6][2]*reg41; reg18=reg14+reg18; reg10=reg31-reg10; reg14=pos_nodes[6][2]*reg16;
    reg31=pos_nodes[3][2]*reg0; reg28=reg21+reg28; reg21=reg42*pos_nodes[4][1]; reg25=reg32+reg25; reg32=pos_nodes[3][2]*reg27;
    reg33=reg17+reg33; reg17=var_inter[2]*reg5; T reg43=pos_nodes[6][0]*reg16; reg20=reg37+reg20; reg19=reg36+reg19;
    reg36=pos_nodes[4][0]*reg42; reg37=pos_nodes[6][0]*reg41; reg12=reg38-reg12; reg30=reg24-reg30; reg24=pos_nodes[6][1]*reg41;
    reg40=reg35-reg40; reg8=reg26+reg8; reg26=pos_nodes[6][1]*reg16; reg35=pos_nodes[4][1]*reg39; reg38=pos_nodes[4][0]*reg39;
    reg11=reg34-reg11; reg7=reg10+reg7; reg10=pos_nodes[5][1]*reg39; reg34=pos_nodes[7][2]*reg9; reg36=reg19+reg36;
    reg19=reg17*pos_nodes[5][0]; reg35=reg40-reg35; reg40=reg22*pos_nodes[7][0]; reg43=reg20+reg43; reg20=var_inter[1]*var_inter[2];
    reg14=reg18+reg14; reg18=pos_nodes[7][2]*reg22; T reg44=pos_nodes[7][0]*reg9; reg37=reg12+reg37; reg12=pos_nodes[5][0]*reg39;
    reg33=reg31+reg33; reg31=reg42*pos_nodes[4][2]; reg38=reg11-reg38; reg11=var_inter[2]*reg16; reg21=reg28+reg21;
    reg24=reg30+reg24; reg28=pos_nodes[7][1]*reg9; reg32=reg25-reg32; reg25=pos_nodes[4][2]*reg39; reg26=reg8+reg26;
    reg8=pos_nodes[7][1]*reg22; reg30=reg17*pos_nodes[5][1]; reg21=reg30+reg21; reg30=reg11*pos_nodes[6][1]; T reg45=pos_nodes[6][1]*reg20;
    T reg46=reg17*pos_nodes[5][2]; reg18=reg14+reg18; reg35=reg10+reg35; reg28=reg24+reg28; reg44=reg37+reg44;
    reg31=reg33+reg31; reg10=pos_nodes[5][2]*reg39; reg40=reg43+reg40; reg8=reg26+reg8; reg14=var_inter[2]*reg22;
    reg36=reg19+reg36; reg34=reg7+reg34; reg25=reg32-reg25; reg7=reg11*pos_nodes[6][0]; reg19=pos_nodes[6][0]*reg20;
    reg38=reg12+reg38; reg12=reg8*reg34; reg24=reg44*reg18; reg26=reg28*reg18; reg32=reg11*pos_nodes[6][2];
    reg31=reg46+reg31; reg33=reg40*reg34; reg37=pos_nodes[7][0]*reg20; reg19=reg38+reg19; reg45=reg35+reg45;
    reg35=pos_nodes[6][2]*reg20; reg38=reg14*pos_nodes[7][0]; reg7=reg36+reg7; reg25=reg10+reg25; reg10=pos_nodes[7][1]*reg20;
    reg30=reg21+reg30; reg21=reg14*pos_nodes[7][1]; reg36=pos_nodes[7][2]*reg20; reg35=reg25+reg35; reg37=reg19-reg37;
    reg38=reg7+reg38; reg21=reg30+reg21; reg7=reg40*reg28; reg33=reg24-reg33; reg19=reg44*reg8;
    reg12=reg26-reg12; reg10=reg45-reg10; reg32=reg31+reg32; reg25=reg14*pos_nodes[7][2]; reg7=reg19-reg7;
    reg30=reg10*reg33; reg21=pos[1]-reg21; reg31=var_inter[0]*reg10; reg43=reg37*reg12; reg45=var_inter[0]*reg37;
    reg38=pos[0]-reg38; reg25=reg32+reg25; reg36=reg35-reg36; reg32=reg44*reg36; reg35=reg37*reg34;
    reg46=reg40*reg36; reg25=pos[2]-reg25; T reg47=reg37*reg18; T reg48=reg28*reg36; T reg49=reg10*reg34;
    T reg50=reg8*reg36; T reg51=reg10*reg18; T reg52=var_inter[1]*reg28; reg31=reg21+reg31; reg21=var_inter[0]*reg36;
    reg45=reg38+reg45; reg38=reg36*reg7; reg43=reg30-reg43; reg30=var_inter[1]*reg44; reg31=reg52+reg31;
    reg38=reg43-reg38; reg43=var_inter[1]*reg34; reg52=var_inter[2]*reg40; reg21=reg25+reg21; reg25=reg44*reg10;
    T reg53=reg37*reg28; T reg54=reg40*reg10; T reg55=reg37*reg8; reg32=reg35-reg32; reg50=reg51-reg50;
    reg46=reg47-reg46; T reg56=var_inter[2]*reg8; reg48=reg49-reg48; reg45=reg30+reg45; reg12=reg12/reg38;
    reg50=reg50/reg38; reg30=var_inter[2]*reg18; reg31=reg56+reg31; reg48=reg48/reg38; reg25=reg53-reg25;
    reg21=reg43+reg21; reg32=reg32/reg38; reg46=reg46/reg38; reg45=reg52+reg45; reg54=reg55-reg54;
    reg33=reg33/reg38; reg7=reg7/reg38; reg21=reg30+reg21; reg54=reg54/reg38; reg32=reg31*reg32;
    reg48=reg45*reg48; reg46=reg31*reg46; reg50=reg45*reg50; reg33=reg31*reg33; reg12=reg45*reg12;
    reg38=reg25/reg38; reg38=reg21*reg38; reg46=reg50-reg46; reg48=reg32-reg48; reg54=reg21*reg54;
    reg12=reg33-reg12; reg7=reg21*reg7; var_inter[1]+=reg54+reg46; var_inter[2]+=reg48-reg38; var_inter[0]+=reg12-reg7;

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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=1-var_inter[2]; T reg3=reg1*reg0; reg1=var_inter[0]*reg1;
    T reg4=reg1*reg2; T reg5=reg3*reg2; T reg6=var_inter[0]*var_inter[1]; reg5=val[0]*reg5; T reg7=reg2*reg6;
    reg0=var_inter[1]*reg0; reg4=val[1]*reg4; reg7=val[2]*reg7; reg2=reg2*reg0; reg4=reg5+reg4;
    reg3=var_inter[2]*reg3; reg7=reg4+reg7; reg2=val[3]*reg2; reg1=var_inter[2]*reg1; reg3=val[4]*reg3;
    reg2=reg7+reg2; reg3=reg2+reg3; reg1=val[5]*reg1; reg6=var_inter[2]*reg6; reg1=reg3+reg1;
    reg6=val[6]*reg6; reg0=var_inter[2]*reg0; reg6=reg1+reg6; reg0=val[7]*reg0; res=reg6+reg0;

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
