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
    T reg0=0.25*nodes[0]->pos[1]; T reg1=0.25*nodes[1]->pos[1]; T reg2=0.25*nodes[0]->pos[2]; T reg3=0.25*nodes[1]->pos[2]; T reg4=0.25*nodes[2]->pos[1];
    T reg5=reg0+reg1; T reg6=reg2+reg3; T reg7=0.25*nodes[2]->pos[2]; reg0=reg1-reg0; reg2=reg3-reg2;
    reg1=reg6+reg7; reg3=0.25*nodes[3]->pos[2]; reg6=reg7-reg6; T reg8=reg4+reg5; T reg9=0.25*nodes[3]->pos[1];
    reg5=reg4-reg5; reg0=reg4+reg0; reg2=reg7+reg2; reg4=0.25*nodes[1]->pos[0]; reg7=0.25*nodes[0]->pos[0];
    reg5=reg5+reg9; T reg10=0.25*nodes[4]->pos[1]; T reg11=0.25*nodes[4]->pos[2]; reg1=reg1+reg3; reg2=reg2-reg3;
    reg6=reg3+reg6; reg8=reg9+reg8; reg3=reg4+reg7; reg9=reg0-reg9; reg0=0.25*nodes[2]->pos[0];
    reg7=reg4-reg7; reg2=reg2-reg11; reg6=reg6-reg11; reg4=0.25*nodes[5]->pos[2]; reg1=reg11-reg1;
    reg8=reg10-reg8; reg11=reg0-reg3; reg9=reg9-reg10; T reg12=0.25*nodes[3]->pos[0]; T reg13=0.25*nodes[5]->pos[1];
    reg10=reg5-reg10; reg7=reg7+reg0; reg5=0.25*nodes[4]->pos[0]; reg9=reg13+reg9; reg11=reg12+reg11;
    reg8=reg13+reg8; reg7=reg7-reg12; reg6=reg6-reg4; reg13=reg10-reg13; reg10=0.25*nodes[6]->pos[1];
    T reg14=0.25*nodes[6]->pos[2]; reg1=reg1+reg4; reg3=reg0+reg3; reg2=reg4+reg2; reg13=reg13+reg10;
    reg11=reg11-reg5; reg0=0.25*nodes[7]->pos[1]; reg9=reg10+reg9; reg8=reg10+reg8; reg2=reg14+reg2;
    reg7=reg7-reg5; reg6=reg14+reg6; reg4=0.25*nodes[5]->pos[0]; reg3=reg12+reg3; reg14=reg1+reg14;
    reg1=0.25*nodes[7]->pos[2]; reg9=reg9-reg0; reg2=reg2-reg1; reg3=reg5-reg3; reg5=0.25*nodes[6]->pos[0];
    reg11=reg11-reg4; reg7=reg7+reg4; reg8=reg0+reg8; reg6=reg1+reg6; reg0=reg13+reg0;
    reg1=reg14+reg1; reg7=reg7+reg5; reg10=reg8*reg2; reg12=0.25*nodes[7]->pos[0]; reg3=reg4+reg3;
    reg4=reg0*reg1; reg1=reg1*reg9; reg8=reg6*reg8; reg11=reg5+reg11; reg3=reg5+reg3;
    reg9=reg6*reg9; reg2=reg0*reg2; reg10=reg1-reg10; reg7=reg7-reg12; reg8=reg4-reg8;
    reg11=reg12+reg11; reg10=reg11*reg10; reg3=reg12+reg3; reg8=reg7*reg8; reg2=reg9-reg2;
    reg10=reg8-reg10; reg2=reg3*reg2; T det_jac=reg10+reg2;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1],nodes[4],nodes[7],nodes[6],nodes[5]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[2]; T reg1=1-var_inter[1]; T reg2=1-var_inter[0]; T reg3=reg0*reg2; T reg4=reg0*var_inter[0];
    T reg5=reg1*var_inter[0]; T reg6=reg1*reg2; T reg7=pos_nodes[0][0]*reg3; T reg8=pos_nodes[1][0]*reg4; T reg9=pos_nodes[0][0]*reg6;
    T reg10=reg5*pos_nodes[1][0]; T reg11=reg5*pos_nodes[1][1]; T reg12=reg6*pos_nodes[0][1]; T reg13=pos_nodes[0][2]*reg3; T reg14=pos_nodes[1][2]*reg4;
    T reg15=reg6*pos_nodes[0][2]; T reg16=reg5*pos_nodes[1][2]; T reg17=pos_nodes[1][1]*reg4; T reg18=pos_nodes[0][1]*reg3; T reg19=var_inter[0]*var_inter[1];
    reg14=reg13+reg14; reg13=pos_nodes[2][2]*reg4; T reg20=pos_nodes[2][0]*reg4; reg8=reg7+reg8; reg7=reg2*var_inter[1];
    reg10=reg9+reg10; reg9=reg19*pos_nodes[2][0]; T reg21=reg19*pos_nodes[2][1]; reg11=reg12+reg11; reg17=reg18+reg17;
    reg12=reg0*reg5; reg18=reg6*reg0; T reg22=pos_nodes[2][1]*reg4; T reg23=reg19*pos_nodes[2][2]; reg16=reg15+reg16;
    reg15=reg1*reg0; reg8=reg20-reg8; reg20=pos_nodes[3][0]*reg3; T reg24=reg12*pos_nodes[1][1]; reg23=reg16+reg23;
    reg9=reg10+reg9; reg10=reg7*pos_nodes[3][0]; reg16=reg7*pos_nodes[3][1]; reg21=reg11+reg21; reg11=pos_nodes[0][0]*reg18;
    T reg25=reg12*pos_nodes[1][0]; T reg26=reg0*reg19; T reg27=reg18*pos_nodes[0][1]; T reg28=pos_nodes[3][1]*reg3; reg17=reg22-reg17;
    reg22=pos_nodes[1][1]*reg15; T reg29=pos_nodes[0][1]*reg15; T reg30=reg0*var_inter[1]; T reg31=pos_nodes[0][0]*reg15; reg14=reg13-reg14;
    reg13=reg2*var_inter[2]; T reg32=reg7*pos_nodes[3][2]; T reg33=pos_nodes[3][2]*reg3; T reg34=pos_nodes[1][0]*reg15; T reg35=reg18*pos_nodes[0][2];
    T reg36=pos_nodes[4][2]*reg13; reg16=reg21+reg16; reg33=reg14+reg33; reg28=reg17+reg28; reg14=reg6*pos_nodes[4][2];
    reg32=reg23+reg32; reg25=reg11+reg25; reg11=reg26*pos_nodes[2][0]; reg17=reg12*pos_nodes[1][2]; reg21=reg6*pos_nodes[4][1];
    reg23=pos_nodes[4][1]*reg13; reg31=reg34-reg31; reg34=pos_nodes[2][1]*reg30; reg20=reg8+reg20; reg8=pos_nodes[4][0]*reg13;
    T reg37=pos_nodes[0][2]*reg15; T reg38=pos_nodes[1][2]*reg15; reg29=reg22-reg29; reg22=pos_nodes[2][0]*reg30; T reg39=reg26*pos_nodes[2][1];
    reg24=reg27+reg24; reg27=reg6*pos_nodes[4][0]; reg0=reg0*reg7; T reg40=var_inter[0]*var_inter[2]; reg10=reg9+reg10;
    reg36=reg33-reg36; reg23=reg28-reg23; reg9=pos_nodes[5][1]*reg40; reg28=pos_nodes[2][2]*reg30; reg37=reg38-reg37;
    reg32=reg14-reg32; reg16=reg21-reg16; reg14=reg5*pos_nodes[5][1]; reg21=reg5*pos_nodes[5][2]; reg39=reg24+reg39;
    reg24=reg0*pos_nodes[3][1]; reg17=reg35+reg17; reg33=reg26*pos_nodes[2][2]; reg35=pos_nodes[5][2]*reg40; reg10=reg27-reg10;
    reg27=reg5*pos_nodes[5][0]; reg11=reg25+reg11; reg25=reg0*pos_nodes[3][0]; reg38=pos_nodes[5][0]*reg40; reg8=reg20-reg8;
    reg20=pos_nodes[3][0]*reg30; reg22=reg31+reg22; reg31=reg1*var_inter[2]; T reg41=reg6*var_inter[2]; reg34=reg29+reg34;
    reg29=pos_nodes[3][1]*reg30; T reg42=reg5*var_inter[2]; T reg43=reg19*pos_nodes[6][2]; reg14=reg16+reg14; reg16=reg19*pos_nodes[6][1];
    T reg44=pos_nodes[6][0]*reg40; reg38=reg8-reg38; reg24=reg39+reg24; reg21=reg32+reg21; reg8=reg41*pos_nodes[4][1];
    reg28=reg37+reg28; reg32=pos_nodes[3][2]*reg30; reg37=pos_nodes[4][0]*reg31; reg20=reg22-reg20; reg35=reg36-reg35;
    reg22=pos_nodes[6][2]*reg40; reg36=reg0*pos_nodes[3][2]; reg33=reg17+reg33; reg29=reg34-reg29; reg17=pos_nodes[4][1]*reg31;
    reg9=reg23-reg9; reg23=pos_nodes[6][1]*reg40; reg34=reg41*pos_nodes[4][0]; reg25=reg11+reg25; reg27=reg10+reg27;
    reg10=reg19*pos_nodes[6][0]; reg32=reg28-reg32; reg11=pos_nodes[4][2]*reg31; reg28=pos_nodes[5][0]*reg31; reg37=reg20-reg37;
    reg20=reg7*pos_nodes[7][1]; reg16=reg14+reg16; reg34=reg25+reg34; reg14=reg42*pos_nodes[5][0]; reg25=var_inter[1]*var_inter[2];
    reg22=reg35+reg22; reg35=pos_nodes[7][2]*reg13; reg39=reg41*pos_nodes[4][2]; reg36=reg33+reg36; reg33=pos_nodes[5][1]*reg31;
    T reg45=reg19*var_inter[2]; reg17=reg29-reg17; reg43=reg21+reg43; reg21=reg7*pos_nodes[7][2]; reg29=pos_nodes[7][0]*reg13;
    reg44=reg38+reg44; reg10=reg27+reg10; reg27=reg7*pos_nodes[7][0]; reg8=reg24+reg8; reg24=reg42*pos_nodes[5][1];
    reg23=reg9+reg23; reg9=pos_nodes[7][1]*reg13; reg21=reg43+reg21; reg11=reg32-reg11; reg32=pos_nodes[5][2]*reg31;
    reg27=reg10+reg27; reg29=reg44+reg29; reg10=reg7*var_inter[2]; reg33=reg17+reg33; reg17=pos_nodes[6][1]*reg25;
    reg24=reg8+reg24; reg39=reg36+reg39; reg8=reg42*pos_nodes[5][2]; reg35=reg22+reg35; reg22=reg45*pos_nodes[6][1];
    reg36=reg45*pos_nodes[6][0]; reg14=reg34+reg14; reg34=pos_nodes[6][0]*reg25; reg28=reg37+reg28; reg9=reg23+reg9;
    reg20=reg16+reg20; reg16=reg20*reg35; reg23=reg9*reg21; reg34=reg28+reg34; reg28=pos_nodes[7][0]*reg25;
    reg32=reg11+reg32; reg17=reg33+reg17; reg11=pos_nodes[7][1]*reg25; reg33=reg27*reg35; reg37=reg10*pos_nodes[7][0];
    reg36=reg14+reg36; reg14=pos_nodes[6][2]*reg25; reg38=reg29*reg21; reg43=reg10*pos_nodes[7][1]; reg8=reg39+reg8;
    reg39=reg45*pos_nodes[6][2]; reg22=reg24+reg22; reg33=reg38-reg33; reg24=reg27*reg9; reg44=reg29*reg20;
    reg16=reg23-reg16; T reg46=reg10*pos_nodes[7][2]; reg39=reg8+reg39; reg11=reg17-reg11; reg37=reg36+reg37;
    reg43=reg22+reg43; reg28=reg34-reg28; reg14=reg32+reg14; reg8=pos_nodes[7][2]*reg25; reg24=reg44-reg24;
    reg37=pos[0]-reg37; reg17=reg11*reg33; reg43=pos[1]-reg43; reg22=reg28*reg16; reg32=var_inter[0]*reg11;
    reg34=var_inter[0]*reg28; reg8=reg14-reg8; reg46=reg39+reg46; reg14=reg9*reg8; reg36=reg11*reg35;
    reg39=reg20*reg8; T reg47=reg11*reg21; T reg48=reg8*reg24; reg22=reg17-reg22; reg17=reg29*reg8;
    T reg49=reg28*reg35; T reg50=reg27*reg8; reg46=pos[2]-reg46; T reg51=reg28*reg21; T reg52=var_inter[0]*reg8;
    T reg53=var_inter[1]*reg29; reg34=reg37+reg34; reg32=reg43+reg32; reg37=var_inter[1]*reg9; reg43=reg29*reg11;
    T reg54=reg28*reg9; T reg55=reg27*reg11; T reg56=reg28*reg20; reg17=reg49-reg17; reg14=reg36-reg14;
    reg39=reg47-reg39; T reg57=var_inter[2]*reg20; reg34=reg53+reg34; reg48=reg22-reg48; reg52=reg46+reg52;
    reg22=var_inter[1]*reg35; reg50=reg51-reg50; reg32=reg37+reg32; reg37=var_inter[2]*reg27; reg34=reg37+reg34;
    reg50=reg50/reg48; reg39=reg39/reg48; reg37=var_inter[2]*reg21; reg14=reg14/reg48; reg33=reg33/reg48;
    reg32=reg57+reg32; reg17=reg17/reg48; reg43=reg54-reg43; reg16=reg16/reg48; reg52=reg22+reg52;
    reg55=reg56-reg55; reg33=reg33*reg32; reg39=reg34*reg39; reg50=reg50*reg32; reg14=reg34*reg14;
    reg17=reg32*reg17; reg16=reg34*reg16; reg43=reg43/reg48; reg55=reg55/reg48; reg52=reg37+reg52;
    reg48=reg24/reg48; reg48=reg48*reg52; reg16=reg33-reg16; reg55=reg52*reg55; reg50=reg39-reg50;
    reg43=reg52*reg43; reg14=reg17-reg14; var_inter[0]=reg16-reg48; var_inter[1]=reg55+reg50; var_inter[2]=reg14-reg43;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[2]; T reg2=1-var_inter[1]; T reg3=reg0*reg2; T reg4=var_inter[0]*reg2;
    T reg5=reg0*reg1; T reg6=var_inter[0]*reg1; T reg7=pos_nodes[1][0]*reg4; T reg8=pos_nodes[0][0]*reg3; T reg9=pos_nodes[1][0]*reg6;
    T reg10=pos_nodes[0][0]*reg5; T reg11=pos_nodes[1][2]*reg4; T reg12=pos_nodes[0][2]*reg3; T reg13=pos_nodes[1][2]*reg6; T reg14=pos_nodes[0][2]*reg5;
    T reg15=pos_nodes[1][1]*reg4; T reg16=pos_nodes[0][1]*reg3; T reg17=pos_nodes[1][1]*reg6; T reg18=pos_nodes[0][1]*reg5; T reg19=var_inter[0]*var_inter[1];
    T reg20=var_inter[1]*reg0; reg15=reg16+reg15; reg16=pos_nodes[2][1]*reg19; reg17=reg18+reg17; reg18=pos_nodes[2][1]*reg6;
    T reg21=pos_nodes[2][0]*reg6; T reg22=reg1*reg2; T reg23=pos_nodes[2][2]*reg6; reg7=reg8+reg7; reg8=reg4*reg1;
    T reg24=reg3*reg1; reg11=reg12+reg11; reg12=pos_nodes[2][0]*reg19; T reg25=pos_nodes[2][2]*reg19; reg13=reg14+reg13;
    reg9=reg10+reg9; reg10=pos_nodes[0][1]*reg22; reg14=var_inter[2]*reg0; T reg26=pos_nodes[0][0]*reg24; T reg27=pos_nodes[3][0]*reg20;
    T reg28=pos_nodes[1][0]*reg8; reg12=reg7+reg12; reg7=pos_nodes[1][1]*reg22; T reg29=pos_nodes[3][0]*reg5; reg9=reg21-reg9;
    reg17=reg18-reg17; reg18=pos_nodes[3][1]*reg5; reg21=reg19*reg1; reg25=reg11+reg25; reg11=pos_nodes[3][2]*reg5;
    reg13=reg23-reg13; reg23=pos_nodes[3][2]*reg20; T reg30=var_inter[1]*reg1; T reg31=pos_nodes[1][1]*reg8; T reg32=pos_nodes[0][0]*reg22;
    T reg33=pos_nodes[1][0]*reg22; reg16=reg15+reg16; reg15=pos_nodes[3][1]*reg20; T reg34=pos_nodes[0][1]*reg24; T reg35=pos_nodes[1][2]*reg8;
    T reg36=pos_nodes[0][2]*reg24; T reg37=reg3*pos_nodes[4][1]; T reg38=pos_nodes[4][1]*reg14; reg18=reg17+reg18; reg27=reg12+reg27;
    reg12=reg3*pos_nodes[4][2]; reg17=pos_nodes[4][2]*reg14; reg28=reg26+reg28; reg26=pos_nodes[2][0]*reg21; reg11=reg13+reg11;
    reg13=pos_nodes[2][1]*reg30; reg15=reg16+reg15; reg31=reg34+reg31; reg23=reg25+reg23; reg16=pos_nodes[2][1]*reg21;
    reg25=pos_nodes[0][2]*reg22; reg34=pos_nodes[1][2]*reg22; reg10=reg7-reg10; reg7=pos_nodes[4][0]*reg3; T reg39=var_inter[0]*var_inter[2];
    reg1=reg20*reg1; reg29=reg9+reg29; reg9=pos_nodes[4][0]*reg14; T reg40=pos_nodes[2][0]*reg30; reg32=reg33-reg32;
    reg33=pos_nodes[3][1]*reg1; reg16=reg31+reg16; reg31=reg4*pos_nodes[5][1]; reg15=reg37-reg15; reg40=reg32+reg40;
    reg32=pos_nodes[3][0]*reg30; reg37=pos_nodes[5][1]*reg39; reg38=reg18-reg38; reg18=pos_nodes[3][1]*reg30; T reg41=var_inter[2]*reg2;
    reg25=reg34-reg25; reg34=pos_nodes[2][2]*reg30; T reg42=pos_nodes[2][2]*reg21; reg35=reg36+reg35; reg17=reg11-reg17;
    reg11=pos_nodes[5][2]*reg39; reg36=var_inter[2]*reg3; reg23=reg12-reg23; reg12=reg4*pos_nodes[5][2]; reg27=reg7-reg27;
    reg7=reg4*pos_nodes[5][0]; T reg43=pos_nodes[5][0]*reg39; reg9=reg29-reg9; reg13=reg10+reg13; reg26=reg28+reg26;
    reg10=pos_nodes[3][0]*reg1; reg28=pos_nodes[3][2]*reg30; reg7=reg27+reg7; reg27=pos_nodes[6][2]*reg39; reg11=reg17-reg11;
    reg17=reg19*pos_nodes[6][0]; reg31=reg15+reg31; reg15=reg19*pos_nodes[6][1]; reg43=reg9-reg43; reg9=pos_nodes[4][0]*reg36;
    reg33=reg16+reg33; reg16=reg36*pos_nodes[4][1]; reg34=reg25+reg34; reg10=reg26+reg10; reg42=reg35+reg42;
    reg25=pos_nodes[3][2]*reg1; reg26=pos_nodes[6][0]*reg39; reg29=var_inter[2]*reg4; reg12=reg23+reg12; reg23=reg19*pos_nodes[6][2];
    reg35=pos_nodes[4][0]*reg41; reg32=reg40-reg32; reg37=reg38-reg37; reg38=pos_nodes[4][1]*reg41; reg18=reg13-reg18;
    reg13=pos_nodes[6][1]*reg39; reg38=reg18-reg38; reg18=pos_nodes[5][1]*reg41; reg40=var_inter[1]*var_inter[2]; T reg44=reg36*pos_nodes[4][2];
    T reg45=pos_nodes[7][2]*reg20; reg23=reg12+reg23; reg28=reg34-reg28; reg12=reg29*pos_nodes[5][1]; reg16=reg33+reg16;
    reg33=pos_nodes[4][2]*reg41; reg34=pos_nodes[7][0]*reg14; reg25=reg42+reg25; reg42=pos_nodes[7][1]*reg14; reg13=reg37+reg13;
    reg37=pos_nodes[7][2]*reg14; reg27=reg11+reg27; reg11=var_inter[2]*reg19; reg17=reg7+reg17; reg7=reg29*pos_nodes[5][0];
    reg15=reg31+reg15; reg31=pos_nodes[7][1]*reg20; T reg46=reg20*pos_nodes[7][0]; reg35=reg32-reg35; reg32=pos_nodes[5][0]*reg41;
    reg9=reg10+reg9; reg26=reg43+reg26; reg46=reg17+reg46; reg34=reg26+reg34; reg10=reg20*var_inter[2];
    reg45=reg23+reg45; reg37=reg27+reg37; reg17=pos_nodes[5][2]*reg41; reg18=reg38+reg18; reg33=reg28-reg33;
    reg44=reg25+reg44; reg23=pos_nodes[6][1]*reg40; reg25=reg11*pos_nodes[6][0]; reg26=reg11*pos_nodes[6][1]; reg12=reg16+reg12;
    reg16=reg29*pos_nodes[5][2]; reg42=reg13+reg42; reg32=reg35+reg32; reg31=reg15+reg31; reg7=reg9+reg7;
    reg9=pos_nodes[6][0]*reg40; reg13=reg10*pos_nodes[7][0]; reg15=reg46*reg37; reg9=reg32+reg9; reg27=pos_nodes[7][0]*reg40;
    reg28=pos_nodes[7][1]*reg40; reg23=reg18+reg23; reg18=reg34*reg45; reg25=reg7+reg25; reg7=reg31*reg37;
    reg32=reg42*reg45; reg35=reg11*pos_nodes[6][2]; reg16=reg44+reg16; reg26=reg12+reg26; reg12=pos_nodes[7][1]*reg10;
    reg38=pos_nodes[6][2]*reg40; reg17=reg33+reg17; reg33=reg46*reg42; reg7=reg32-reg7; reg15=reg18-reg15;
    reg43=pos_nodes[7][2]*reg10; reg35=reg16+reg35; reg16=reg34*reg31; reg13=reg25+reg13; reg27=reg9-reg27;
    reg28=reg23-reg28; reg12=reg26+reg12; reg38=reg17+reg38; reg9=pos_nodes[7][2]*reg40; reg9=reg38-reg9;
    reg12=pos[1]-reg12; reg17=reg27*reg7; reg23=var_inter[0]*reg28; reg33=reg16-reg33; reg43=reg35+reg43;
    reg25=var_inter[0]*reg27; reg13=pos[0]-reg13; reg26=reg28*reg15; reg35=var_inter[0]*reg9; reg38=reg27*reg45;
    reg17=reg26-reg17; reg26=reg9*reg33; reg44=reg28*reg45; T reg47=reg31*reg9; T reg48=reg28*reg37;
    T reg49=reg42*reg9; T reg50=reg46*reg9; reg23=reg12+reg23; reg12=reg27*reg37; T reg51=reg34*reg9;
    reg43=pos[2]-reg43; T reg52=var_inter[1]*reg34; T reg53=var_inter[1]*reg42; reg25=reg13+reg25; reg47=reg44-reg47;
    reg50=reg38-reg50; reg26=reg17-reg26; reg13=var_inter[2]*reg46; reg17=var_inter[2]*reg31; reg25=reg52+reg25;
    reg49=reg48-reg49; reg52=reg27*reg31; reg51=reg12-reg51; T reg54=reg46*reg28; T reg55=reg27*reg42;
    reg35=reg43+reg35; reg43=var_inter[1]*reg37; T reg56=reg34*reg28; reg23=reg53+reg23; reg54=reg52-reg54;
    reg49=reg49/reg26; reg15=reg15/reg26; reg56=reg55-reg56; reg47=reg47/reg26; reg50=reg50/reg26;
    reg7=reg7/reg26; reg25=reg13+reg25; reg51=reg51/reg26; reg35=reg43+reg35; reg23=reg17+reg23;
    reg13=var_inter[2]*reg45; reg49=reg25*reg49; reg50=reg50*reg23; reg47=reg25*reg47; reg51=reg51*reg23;
    reg15=reg15*reg23; reg7=reg25*reg7; reg56=reg56/reg26; reg54=reg54/reg26; reg26=reg33/reg26;
    reg35=reg13+reg35; reg49=reg51-reg49; reg56=reg35*reg56; reg50=reg47-reg50; reg54=reg35*reg54;
    reg7=reg15-reg7; reg26=reg26*reg35; var_inter[1]+=reg54+reg50; var_inter[0]+=reg7-reg26; var_inter[2]+=reg49-reg56;

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
