#ifndef LMT_HEXA
#define LMT_HEXA
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Hexa &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 33, 66, 99, 132, 269, 406, 543, 680, 817, }; // fonction de lordre du poly
    static const double values[] = {
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.0,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.0,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.0,
        0.125,0.788675134595,0.788675134595,0.211324865405,
        0.125,0.788675134595,0.211324865405,0.211324865405,
        0.125,0.211324865405,0.788675134595,0.211324865405,
        0.125,0.211324865405,0.211324865405,0.211324865405,
        0.125,0.788675134595,0.788675134595,0.788675134595,
        0.125,0.788675134595,0.211324865405,0.788675134595,
        0.125,0.211324865405,0.788675134595,0.788675134595,
        0.125,0.211324865405,0.211324865405,0.788675134595,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
        0.036968449931412875,0.5,0.962910049886276,0.5,
        0.036968449931412875,0.5,0.037089950113724,0.5,
        0.036968449931412875,0.962910049886276,0.5,0.5,
        0.036968449931412875,0.037089950113724,0.5,0.5,
        0.036968449931412875,0.5,0.5,0.962910049886276,
        0.036968449931412875,0.5,0.5,0.037089950113724,
        0.0117626886145405,0.962910049886276,0.962910049886276,0.5,
        0.0117626886145405,0.037089950113724,0.962910049886276,0.5,
        0.0117626886145405,0.962910049886276,0.037089950113724,0.5,
        0.0117626886145405,0.037089950113724,0.037089950113724,0.5,
        0.0117626886145405,0.962910049886276,0.5,0.962910049886276,
        0.0117626886145405,0.962910049886276,0.5,0.037089950113724,
        0.0117626886145405,0.037089950113724,0.5,0.962910049886276,
        0.0117626886145405,0.037089950113724,0.5,0.037089950113724,
        0.0117626886145405,0.5,0.962910049886276,0.962910049886276,
        0.0117626886145405,0.5,0.037089950113724,0.962910049886276,
        0.0117626886145405,0.5,0.962910049886276,0.037089950113724,
        0.0117626886145405,0.5,0.037089950113724,0.037089950113724,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.66540748184964399999,0.33459251815035600001,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.66540748184964399999,0.33459251815035600001,0.33459251815035600001,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.66540748184964399999,
        0.0515417327839295,0.33459251815035600001,0.33459251815035600001,0.33459251815035600001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.86705626437605750001,0.13294373562394249999,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.86705626437605750001,0.13294373562394249999,0.13294373562394249999,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.86705626437605750001,
        0.028087896845700125,0.13294373562394249999,0.13294373562394249999,0.13294373562394249999,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Hexa &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.25*nodes[1]->pos[2]; T reg1=0.25*nodes[0]->pos[2]; T reg2=0.25*nodes[1]->pos[1]; T reg3=0.25*nodes[0]->pos[1]; T reg4=reg2-reg3;
    T reg5=reg0-reg1; T reg6=0.25*nodes[2]->pos[2]; reg0=reg1+reg0; reg2=reg3+reg2; reg1=0.25*nodes[2]->pos[1];
    reg3=0.25*nodes[1]->pos[0]; reg4=reg1+reg4; T reg7=reg1+reg2; reg5=reg6+reg5; T reg8=reg6-reg0;
    reg6=reg0+reg6; reg0=0.25*nodes[3]->pos[2]; T reg9=0.25*nodes[0]->pos[0]; reg2=reg1-reg2; reg1=0.25*nodes[3]->pos[1];
    T reg10=0.25*nodes[4]->pos[2]; reg6=reg6+reg0; reg5=reg5-reg0; reg8=reg0+reg8; reg7=reg1+reg7;
    reg4=reg4-reg1; reg0=reg3+reg9; T reg11=0.25*nodes[2]->pos[0]; reg9=reg3-reg9; reg3=0.25*nodes[4]->pos[1];
    reg1=reg2+reg1; reg9=reg9+reg11; reg8=reg8-reg10; reg5=reg5-reg10; reg7=reg3-reg7;
    reg4=reg4-reg3; reg2=0.25*nodes[5]->pos[2]; reg6=reg10-reg6; reg10=0.25*nodes[3]->pos[0]; reg3=reg1-reg3;
    reg1=0.25*nodes[5]->pos[1]; T reg12=reg11-reg0; reg4=reg1+reg4; reg7=reg1+reg7; T reg13=0.25*nodes[4]->pos[0];
    reg12=reg10+reg12; reg9=reg9-reg10; reg8=reg8-reg2; reg5=reg2+reg5; T reg14=0.25*nodes[6]->pos[2];
    reg2=reg6+reg2; reg1=reg3-reg1; reg3=0.25*nodes[6]->pos[1]; reg0=reg11+reg0; reg5=reg14+reg5;
    reg4=reg3+reg4; reg0=reg10+reg0; reg9=reg9-reg13; reg12=reg12-reg13; reg6=0.25*nodes[5]->pos[0];
    reg1=reg1+reg3; reg7=reg3+reg7; reg3=0.25*nodes[7]->pos[1]; reg8=reg14+reg8; reg14=reg2+reg14;
    reg2=0.25*nodes[7]->pos[2]; reg9=reg9+reg6; reg10=0.25*nodes[6]->pos[0]; reg0=reg13-reg0; reg1=reg1+reg3;
    reg5=reg5-reg2; reg12=reg12-reg6; reg7=reg3+reg7; reg3=reg4-reg3; reg8=reg2+reg8;
    reg2=reg14+reg2; reg9=reg9+reg10; reg4=0.25*nodes[7]->pos[0]; reg11=reg1*reg2; reg13=reg8*reg7;
    reg0=reg6+reg0; reg7=reg7*reg5; reg2=reg2*reg3; reg12=reg10+reg12; reg0=reg10+reg0;
    reg12=reg4+reg12; reg3=reg8*reg3; reg5=reg1*reg5; reg13=reg11-reg13; reg9=reg9-reg4;
    reg7=reg2-reg7; reg13=reg9*reg13; reg5=reg3-reg5; reg0=reg4+reg0; reg7=reg12*reg7;
    reg5=reg0*reg5; reg7=reg13-reg7; T det_jac=reg7+reg5;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1],nodes[4],nodes[7],nodes[6],nodes[5]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=1-var_inter[2]; T reg3=var_inter[0]*reg0; T reg4=var_inter[0]*reg2;
    T reg5=reg1*reg0; T reg6=reg2*reg1; T reg7=pos_nodes[1][1]*reg3; T reg8=pos_nodes[0][1]*reg5; T reg9=pos_nodes[1][1]*reg4;
    T reg10=pos_nodes[0][1]*reg6; T reg11=pos_nodes[1][0]*reg3; T reg12=pos_nodes[0][0]*reg6; T reg13=pos_nodes[1][0]*reg4; T reg14=pos_nodes[0][0]*reg5;
    T reg15=pos_nodes[1][2]*reg3; T reg16=var_inter[0]*var_inter[1]; T reg17=pos_nodes[0][2]*reg5; T reg18=pos_nodes[1][2]*reg4; T reg19=pos_nodes[0][2]*reg6;
    reg13=reg12+reg13; reg12=reg2*reg3; T reg20=pos_nodes[2][0]*reg4; T reg21=reg5*reg2; reg11=reg14+reg11;
    reg14=reg16*pos_nodes[2][0]; T reg22=pos_nodes[2][1]*reg4; T reg23=pos_nodes[2][2]*reg16; reg9=reg10+reg9; reg15=reg17+reg15;
    reg7=reg8+reg7; reg8=pos_nodes[2][2]*reg4; reg10=reg16*pos_nodes[2][1]; reg17=var_inter[1]*reg1; T reg24=reg2*reg0;
    reg19=reg18+reg19; reg18=pos_nodes[3][2]*reg6; T reg25=pos_nodes[1][1]*reg12; reg19=reg8-reg19; reg8=pos_nodes[0][1]*reg21;
    T reg26=pos_nodes[3][1]*reg17; T reg27=pos_nodes[3][2]*reg17; reg14=reg11+reg14; reg11=pos_nodes[3][0]*reg17; T reg28=pos_nodes[0][0]*reg21;
    T reg29=pos_nodes[1][0]*reg12; T reg30=pos_nodes[1][1]*reg24; T reg31=pos_nodes[0][1]*reg24; reg23=reg15+reg23; reg10=reg7+reg10;
    reg9=reg22-reg9; reg7=pos_nodes[3][1]*reg6; reg15=reg16*reg2; reg22=var_inter[1]*reg2; T reg32=pos_nodes[1][0]*reg24;
    T reg33=pos_nodes[0][0]*reg24; T reg34=var_inter[2]*reg1; reg13=reg20-reg13; reg20=pos_nodes[3][0]*reg6; T reg35=reg15*pos_nodes[2][0];
    T reg36=pos_nodes[4][2]*reg5; T reg37=pos_nodes[4][2]*reg34; reg18=reg19+reg18; reg2=reg17*reg2; reg19=pos_nodes[0][2]*reg24;
    T reg38=pos_nodes[1][2]*reg24; T reg39=reg15*pos_nodes[2][1]; reg31=reg30-reg31; reg30=pos_nodes[2][1]*reg22; reg25=reg8+reg25;
    reg8=pos_nodes[4][0]*reg34; reg26=reg10+reg26; reg10=pos_nodes[4][1]*reg5; T reg40=pos_nodes[4][1]*reg34; reg7=reg9+reg7;
    reg33=reg32-reg33; reg9=pos_nodes[2][0]*reg22; reg32=pos_nodes[4][0]*reg5; T reg41=var_inter[0]*var_inter[2]; reg11=reg14+reg11;
    reg14=pos_nodes[1][2]*reg12; T reg42=pos_nodes[0][2]*reg21; reg29=reg28+reg29; reg20=reg13+reg20; reg27=reg23+reg27;
    reg13=pos_nodes[5][2]*reg41; reg37=reg18-reg37; reg40=reg7-reg40; reg7=pos_nodes[5][1]*reg41; reg18=var_inter[2]*reg0;
    reg23=pos_nodes[5][0]*reg41; reg8=reg20-reg8; reg26=reg10-reg26; reg10=pos_nodes[5][1]*reg3; reg27=reg36-reg27;
    reg20=pos_nodes[2][2]*reg15; reg14=reg42+reg14; reg39=reg25+reg39; reg25=pos_nodes[3][1]*reg2; reg28=pos_nodes[5][2]*reg3;
    reg36=var_inter[2]*reg5; reg19=reg38-reg19; reg38=pos_nodes[2][2]*reg22; reg9=reg33+reg9; reg33=pos_nodes[3][0]*reg22;
    reg42=pos_nodes[3][1]*reg22; reg30=reg31+reg30; reg11=reg32-reg11; reg31=pos_nodes[3][0]*reg2; reg32=pos_nodes[5][0]*reg3;
    reg35=reg29+reg35; reg29=pos_nodes[6][2]*reg16; reg28=reg27+reg28; reg25=reg39+reg25; reg27=pos_nodes[4][1]*reg36;
    reg39=pos_nodes[6][2]*reg41; reg13=reg37-reg13; reg31=reg35+reg31; reg35=pos_nodes[4][0]*reg36; reg37=var_inter[2]*reg3;
    reg38=reg19+reg38; reg19=pos_nodes[3][2]*reg22; reg33=reg9-reg33; reg9=pos_nodes[4][0]*reg18; reg7=reg40-reg7;
    reg40=pos_nodes[6][1]*reg41; T reg43=pos_nodes[3][2]*reg2; T reg44=pos_nodes[6][0]*reg41; reg23=reg8-reg23; reg20=reg14+reg20;
    reg32=reg11+reg32; reg8=pos_nodes[6][1]*reg16; reg10=reg26+reg10; reg42=reg30-reg42; reg11=pos_nodes[4][1]*reg18;
    reg14=pos_nodes[6][0]*reg16; reg26=pos_nodes[7][2]*reg34; reg39=reg13+reg39; reg14=reg32+reg14; reg43=reg20+reg43;
    reg13=pos_nodes[4][2]*reg36; reg29=reg28+reg29; reg35=reg31+reg35; reg20=pos_nodes[5][0]*reg37; reg44=reg23+reg44;
    reg23=reg16*var_inter[2]; reg28=pos_nodes[7][0]*reg34; reg30=reg17*pos_nodes[7][2]; reg31=pos_nodes[7][0]*reg17; reg27=reg25+reg27;
    reg25=pos_nodes[5][1]*reg37; reg32=pos_nodes[5][0]*reg18; reg9=reg33-reg9; reg33=reg17*pos_nodes[7][1]; reg8=reg10+reg8;
    reg11=reg42-reg11; reg10=pos_nodes[5][1]*reg18; reg19=reg38-reg19; reg38=var_inter[1]*var_inter[2]; reg42=pos_nodes[7][1]*reg34;
    reg40=reg7+reg40; reg7=pos_nodes[4][2]*reg18; T reg45=pos_nodes[6][1]*reg38; reg10=reg11+reg10; reg42=reg40+reg42;
    reg30=reg29+reg30; reg13=reg43+reg13; reg33=reg8+reg33; reg8=pos_nodes[5][2]*reg37; reg31=reg14+reg31;
    reg11=pos_nodes[6][0]*reg38; reg28=reg44+reg28; reg32=reg9+reg32; reg20=reg35+reg20; reg9=pos_nodes[6][0]*reg23;
    reg14=reg17*var_inter[2]; reg29=pos_nodes[6][1]*reg23; reg25=reg27+reg25; reg26=reg39+reg26; reg27=pos_nodes[5][2]*reg18;
    reg7=reg19-reg7; reg19=reg31*reg26; reg35=reg28*reg30; reg39=reg33*reg26; reg40=reg42*reg30;
    reg43=pos_nodes[6][2]*reg23; reg8=reg13+reg8; reg11=reg32+reg11; reg27=reg7+reg27; reg7=pos_nodes[6][2]*reg38;
    reg45=reg10+reg45; reg10=pos_nodes[7][0]*reg38; reg13=pos_nodes[7][1]*reg38; reg9=reg20+reg9; reg20=pos_nodes[7][0]*reg14;
    reg32=reg14*pos_nodes[7][1]; reg29=reg25+reg29; reg39=reg40-reg39; reg25=reg28*reg33; reg19=reg35-reg19;
    reg44=reg31*reg42; reg10=reg11-reg10; reg13=reg45-reg13; reg11=reg14*pos_nodes[7][2]; reg20=reg9+reg20;
    reg32=reg29+reg32; reg9=pos_nodes[7][2]*reg38; reg7=reg27+reg7; reg43=reg8+reg43; reg8=reg10*reg39;
    reg32=pos[1]-reg32; reg9=reg7-reg9; reg7=reg13*reg19; reg11=reg43+reg11; reg44=reg25-reg44;
    reg27=var_inter[0]*reg13; reg29=var_inter[0]*reg10; reg20=pos[0]-reg20; reg43=reg13*reg30; reg45=reg33*reg9;
    T reg46=reg9*reg44; T reg47=reg13*reg26; reg8=reg7-reg8; reg7=reg42*reg9; T reg48=reg28*reg9;
    T reg49=reg10*reg30; T reg50=reg10*reg26; T reg51=reg31*reg9; reg11=pos[2]-reg11; reg29=reg20+reg29;
    reg20=var_inter[1]*reg28; T reg52=var_inter[0]*reg9; reg27=reg32+reg27; reg32=var_inter[1]*reg42; T reg53=var_inter[2]*reg33;
    reg51=reg49-reg51; T reg54=reg28*reg13; T reg55=reg10*reg42; T reg56=reg31*reg13; T reg57=reg10*reg33;
    reg48=reg50-reg48; T reg58=var_inter[2]*reg31; reg7=reg47-reg7; reg29=reg20+reg29; reg45=reg43-reg45;
    reg52=reg11+reg52; reg46=reg8-reg46; reg8=var_inter[1]*reg26; reg27=reg32+reg27; reg52=reg8+reg52;
    reg19=reg19/reg46; reg54=reg55-reg54; reg27=reg53+reg27; reg51=reg51/reg46; reg56=reg57-reg56;
    reg8=var_inter[2]*reg30; reg39=reg39/reg46; reg48=reg48/reg46; reg29=reg58+reg29; reg7=reg7/reg46;
    reg45=reg45/reg46; reg48=reg27*reg48; reg7=reg29*reg7; reg51=reg51*reg27; reg45=reg29*reg45;
    reg19=reg19*reg27; reg39=reg29*reg39; reg54=reg54/reg46; reg56=reg56/reg46; reg46=reg44/reg46;
    reg52=reg8+reg52; reg56=reg52*reg56; reg51=reg45-reg51; reg54=reg52*reg54; reg39=reg19-reg39;
    reg7=reg48-reg7; reg46=reg52*reg46; var_inter[0]=reg39-reg46; var_inter[1]=reg56+reg51; var_inter[2]=reg7-reg54;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[2]; T reg1=1-var_inter[0]; T reg2=1-var_inter[1]; T reg3=reg0*reg1; T reg4=reg0*var_inter[0];
    T reg5=var_inter[0]*reg2; T reg6=reg1*reg2; T reg7=var_inter[0]*var_inter[1]; T reg8=reg6*pos_nodes[0][1]; T reg9=pos_nodes[0][0]*reg3;
    T reg10=reg4*pos_nodes[1][0]; T reg11=reg5*pos_nodes[1][2]; T reg12=reg6*pos_nodes[0][2]; T reg13=reg5*pos_nodes[1][1]; T reg14=reg4*pos_nodes[1][2];
    T reg15=reg3*pos_nodes[0][2]; T reg16=reg4*pos_nodes[1][1]; T reg17=pos_nodes[0][1]*reg3; T reg18=reg6*pos_nodes[0][0]; T reg19=reg5*pos_nodes[1][0];
    reg10=reg9+reg10; reg9=reg4*pos_nodes[2][0]; reg16=reg17+reg16; reg17=reg4*pos_nodes[2][1]; T reg20=reg7*pos_nodes[2][0];
    reg13=reg8+reg13; reg8=reg7*pos_nodes[2][1]; reg19=reg18+reg19; reg18=reg6*reg0; T reg21=reg0*reg5;
    T reg22=reg0*reg2; T reg23=reg1*var_inter[1]; T reg24=reg7*pos_nodes[2][2]; T reg25=reg4*pos_nodes[2][2]; reg14=reg15+reg14;
    reg11=reg12+reg11; reg12=reg21*pos_nodes[1][1]; reg20=reg19+reg20; reg15=reg23*pos_nodes[3][0]; reg19=reg18*pos_nodes[0][0];
    T reg26=reg21*pos_nodes[1][0]; T reg27=reg22*pos_nodes[1][1]; T reg28=pos_nodes[0][1]*reg22; T reg29=reg18*pos_nodes[0][1]; T reg30=reg23*pos_nodes[3][1];
    reg8=reg13+reg8; reg16=reg17-reg16; reg13=reg3*pos_nodes[3][2]; reg14=reg25-reg14; reg17=reg0*reg7;
    reg25=reg23*pos_nodes[3][2]; T reg31=reg3*pos_nodes[3][1]; reg24=reg11+reg24; reg11=reg0*var_inter[1]; T reg32=reg3*pos_nodes[3][0];
    reg10=reg9-reg10; reg9=reg22*pos_nodes[1][0]; T reg33=pos_nodes[0][0]*reg22; T reg34=reg1*var_inter[2]; T reg35=reg11*pos_nodes[2][1];
    T reg36=reg34*pos_nodes[4][0]; reg32=reg10+reg32; reg10=var_inter[0]*var_inter[2]; reg31=reg16+reg31; reg16=reg34*pos_nodes[4][1];
    T reg37=reg6*pos_nodes[4][1]; reg30=reg8+reg30; reg12=reg29+reg12; reg8=reg17*pos_nodes[2][1]; reg29=reg22*pos_nodes[0][2];
    T reg38=reg11*pos_nodes[2][0]; reg33=reg9-reg33; reg13=reg14+reg13; reg9=reg34*pos_nodes[4][2]; reg14=reg6*pos_nodes[4][2];
    T reg39=reg22*pos_nodes[1][2]; reg25=reg24+reg25; reg24=reg18*pos_nodes[0][2]; T reg40=reg21*pos_nodes[1][2]; reg0=reg0*reg23;
    T reg41=reg6*pos_nodes[4][0]; reg15=reg20+reg15; reg26=reg19+reg26; reg19=reg17*pos_nodes[2][0]; reg28=reg27-reg28;
    reg40=reg24+reg40; reg20=reg5*pos_nodes[5][0]; reg24=reg5*pos_nodes[5][2]; reg25=reg14-reg25; reg14=pos_nodes[5][2]*reg10;
    reg9=reg13-reg9; reg30=reg37-reg30; reg13=reg5*pos_nodes[5][1]; reg27=reg11*pos_nodes[3][1]; reg19=reg26+reg19;
    reg38=reg33+reg38; reg26=reg11*pos_nodes[3][0]; reg8=reg12+reg8; reg12=reg0*pos_nodes[3][1]; reg33=reg11*pos_nodes[2][2];
    reg29=reg39-reg29; reg37=reg0*pos_nodes[3][0]; reg35=reg28+reg35; reg36=reg32-reg36; reg28=pos_nodes[5][0]*reg10;
    reg32=reg6*var_inter[2]; reg15=reg41-reg15; reg39=var_inter[2]*reg2; reg41=reg17*pos_nodes[2][2]; T reg42=pos_nodes[5][1]*reg10;
    reg16=reg31-reg16; reg33=reg29+reg33; reg20=reg15+reg20; reg15=reg11*pos_nodes[3][2]; reg29=reg39*pos_nodes[4][0];
    reg26=reg38-reg26; reg31=pos_nodes[6][2]*reg7; reg27=reg35-reg27; reg24=reg25+reg24; reg25=pos_nodes[6][0]*reg10;
    reg35=reg5*var_inter[2]; reg41=reg40+reg41; reg38=reg0*pos_nodes[3][2]; reg40=pos_nodes[6][0]*reg7; reg14=reg9-reg14;
    reg9=pos_nodes[6][2]*reg10; T reg43=pos_nodes[6][1]*reg7; T reg44=reg32*pos_nodes[4][0]; reg13=reg30+reg13; reg28=reg36-reg28;
    reg42=reg16-reg42; reg16=pos_nodes[6][1]*reg10; reg37=reg19+reg37; reg12=reg8+reg12; reg8=reg32*pos_nodes[4][1];
    reg19=reg39*pos_nodes[4][1]; reg16=reg42+reg16; reg30=pos_nodes[7][0]*reg23; reg25=reg28+reg25; reg40=reg20+reg40;
    reg20=reg34*pos_nodes[7][2]; reg9=reg14+reg9; reg14=reg34*pos_nodes[7][1]; reg28=reg23*pos_nodes[7][2]; reg38=reg41+reg38;
    reg44=reg37+reg44; reg31=reg24+reg31; reg24=pos_nodes[5][0]*reg35; reg43=reg13+reg43; reg13=reg23*pos_nodes[7][1];
    reg36=pos_nodes[7][0]*reg34; reg19=reg27-reg19; reg27=pos_nodes[5][1]*reg39; reg37=pos_nodes[5][1]*reg35; reg8=reg12+reg8;
    reg15=reg33-reg15; reg12=reg39*pos_nodes[4][2]; reg33=var_inter[2]*reg7; reg41=var_inter[1]*var_inter[2]; reg29=reg26-reg29;
    reg26=pos_nodes[5][0]*reg39; reg42=reg32*pos_nodes[4][2]; T reg45=var_inter[2]*reg23; T reg46=pos_nodes[6][1]*reg41; T reg47=pos_nodes[6][0]*reg33;
    T reg48=pos_nodes[5][2]*reg35; reg42=reg38+reg42; reg27=reg19+reg27; reg28=reg31+reg28; reg14=reg16+reg14;
    reg36=reg25+reg36; reg37=reg8+reg37; reg8=pos_nodes[6][1]*reg33; reg12=reg15-reg12; reg15=pos_nodes[5][2]*reg39;
    reg13=reg43+reg13; reg26=reg29+reg26; reg16=pos_nodes[6][0]*reg41; reg24=reg44+reg24; reg30=reg40+reg30;
    reg20=reg9+reg20; reg8=reg37+reg8; reg9=reg45*pos_nodes[7][1]; reg19=pos_nodes[7][0]*reg41; reg46=reg27+reg46;
    reg25=reg41*pos_nodes[7][1]; reg15=reg12+reg15; reg12=pos_nodes[6][2]*reg41; reg27=pos_nodes[7][0]*reg45; reg29=reg30*reg20;
    reg31=reg36*reg28; reg37=reg13*reg20; reg38=reg14*reg28; reg40=pos_nodes[6][2]*reg33; reg48=reg42+reg48;
    reg47=reg24+reg47; reg16=reg26+reg16; reg24=reg45*pos_nodes[7][2]; reg26=reg36*reg13; reg37=reg38-reg37;
    reg29=reg31-reg29; reg42=reg30*reg14; reg12=reg15+reg12; reg40=reg48+reg40; reg27=reg47+reg27;
    reg19=reg16-reg19; reg25=reg46-reg25; reg15=reg41*pos_nodes[7][2]; reg9=reg8+reg9; reg27=pos[0]-reg27;
    reg15=reg12-reg15; reg42=reg26-reg42; reg8=reg25*reg29; reg9=pos[1]-reg9; reg12=var_inter[0]*reg19;
    reg16=var_inter[0]*reg25; reg24=reg40+reg24; reg40=reg19*reg37; reg43=var_inter[1]*reg36; reg12=reg27+reg12;
    reg27=reg36*reg15; reg44=reg19*reg20; reg46=var_inter[1]*reg14; reg47=reg30*reg15; reg16=reg9+reg16;
    reg9=var_inter[0]*reg15; reg48=reg19*reg28; T reg49=reg14*reg15; reg24=pos[2]-reg24; reg40=reg8-reg40;
    reg8=reg15*reg42; T reg50=reg25*reg20; T reg51=reg13*reg15; T reg52=reg25*reg28; reg51=reg52-reg51;
    reg9=reg24+reg9; reg24=var_inter[1]*reg20; reg47=reg48-reg47; reg16=reg46+reg16; reg8=reg40-reg8;
    reg40=reg36*reg25; reg46=var_inter[2]*reg30; reg12=reg43+reg12; reg43=reg19*reg14; T reg53=reg30*reg25;
    T reg54=reg19*reg13; T reg55=var_inter[2]*reg13; reg27=reg44-reg27; reg49=reg50-reg49; reg37=reg37/reg8;
    reg12=reg46+reg12; reg29=reg29/reg8; reg46=var_inter[2]*reg28; reg16=reg55+reg16; reg9=reg24+reg9;
    reg47=reg47/reg8; reg51=reg51/reg8; reg49=reg49/reg8; reg27=reg27/reg8; reg53=reg54-reg53;
    reg40=reg43-reg40; reg9=reg46+reg9; reg42=reg42/reg8; reg53=reg53/reg8; reg8=reg40/reg8;
    reg37=reg12*reg37; reg29=reg29*reg16; reg51=reg12*reg51; reg47=reg47*reg16; reg49=reg12*reg49;
    reg27=reg16*reg27; reg37=reg29-reg37; reg42=reg9*reg42; reg53=reg9*reg53; reg47=reg51-reg47;
    reg8=reg9*reg8; reg49=reg27-reg49; var_inter[0]+=reg37-reg42; var_inter[1]+=reg53+reg47; var_inter[2]+=reg49-reg8;

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
    T reg4=var_inter[0]*var_inter[1]; T reg5=reg3*reg2; T reg6=reg1*reg2; reg6=val[1]*reg6; reg5=val[0]*reg5;
    reg0=var_inter[1]*reg0; T reg7=reg2*reg4; reg6=reg5+reg6; reg7=val[2]*reg7; reg2=reg2*reg0;
    reg7=reg6+reg7; reg2=val[3]*reg2; reg3=var_inter[2]*reg3; reg3=val[4]*reg3; reg1=var_inter[2]*reg1;
    reg2=reg7+reg2; reg3=reg2+reg3; reg1=val[5]*reg1; reg4=var_inter[2]*reg4; reg1=reg3+reg1;
    reg4=val[6]*reg4; reg0=var_inter[2]*reg0; reg4=reg1+reg4; reg0=val[7]*reg0; res=reg4+reg0;

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
