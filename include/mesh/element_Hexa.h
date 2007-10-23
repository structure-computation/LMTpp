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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=1-var_inter[2]; T reg3=reg1*reg0; T reg4=var_inter[0]*reg1;
    T reg5=reg2*reg0; T reg6=reg2*var_inter[0]; T reg7=reg5*pos_nodes[0][2]; T reg8=reg4*pos_nodes[1][1]; T reg9=reg3*pos_nodes[0][1];
    T reg10=var_inter[0]*var_inter[1]; T reg11=reg6*pos_nodes[1][1]; T reg12=reg5*pos_nodes[0][1]; T reg13=reg5*pos_nodes[0][0]; T reg14=reg6*pos_nodes[1][0];
    T reg15=reg4*pos_nodes[1][2]; T reg16=reg3*pos_nodes[0][2]; T reg17=reg3*pos_nodes[0][0]; T reg18=reg4*pos_nodes[1][0]; T reg19=reg6*pos_nodes[1][2];
    T reg20=reg2*reg1; T reg21=reg6*pos_nodes[2][0]; T reg22=var_inter[1]*reg0; reg19=reg7+reg19; reg7=reg3*reg2;
    T reg23=reg10*pos_nodes[2][2]; reg15=reg16+reg15; reg16=reg6*pos_nodes[2][1]; T reg24=reg6*pos_nodes[2][2]; reg11=reg12+reg11;
    reg12=reg2*reg4; reg14=reg13+reg14; reg18=reg17+reg18; reg8=reg9+reg8; reg9=reg10*pos_nodes[2][1];
    reg13=reg10*pos_nodes[2][0]; reg17=reg20*pos_nodes[1][0]; T reg25=reg20*pos_nodes[0][0]; T reg26=reg2*reg10; reg11=reg16-reg11;
    reg16=reg5*pos_nodes[3][1]; reg9=reg8+reg9; reg8=reg22*pos_nodes[3][1]; T reg27=reg7*pos_nodes[0][1]; T reg28=reg12*pos_nodes[1][1];
    reg19=reg24-reg19; reg24=reg5*pos_nodes[3][2]; reg23=reg15+reg23; reg15=reg22*pos_nodes[3][2]; T reg29=var_inter[2]*reg0;
    reg14=reg21-reg14; reg21=reg5*pos_nodes[3][0]; reg13=reg18+reg13; reg18=reg22*pos_nodes[3][0]; T reg30=reg7*pos_nodes[0][0];
    T reg31=reg12*pos_nodes[1][0]; T reg32=reg20*pos_nodes[1][1]; T reg33=reg20*pos_nodes[0][1]; T reg34=reg2*var_inter[1]; reg31=reg30+reg31;
    reg25=reg17-reg25; reg17=reg29*pos_nodes[4][2]; reg24=reg19+reg24; reg18=reg13+reg18; reg8=reg9+reg8;
    reg9=reg34*pos_nodes[2][0]; reg33=reg32-reg33; reg13=reg20*pos_nodes[0][2]; reg19=reg20*pos_nodes[1][2]; reg30=reg34*pos_nodes[2][1];
    reg32=reg26*pos_nodes[2][1]; reg28=reg27+reg28; reg27=var_inter[0]*var_inter[2]; reg21=reg14+reg21; reg14=reg29*pos_nodes[4][0];
    reg16=reg11+reg16; reg11=reg29*pos_nodes[4][1]; T reg35=reg12*pos_nodes[1][2]; T reg36=reg7*pos_nodes[0][2]; T reg37=reg3*pos_nodes[4][1];
    T reg38=reg26*pos_nodes[2][0]; reg15=reg23+reg15; reg23=reg3*pos_nodes[4][0]; T reg39=reg3*pos_nodes[4][2]; reg2=reg2*reg22;
    T reg40=reg27*pos_nodes[5][1]; reg11=reg16-reg11; reg8=reg37-reg8; reg16=reg4*pos_nodes[5][1]; reg38=reg31+reg38;
    reg32=reg28+reg32; reg28=reg2*pos_nodes[3][1]; reg13=reg19-reg13; reg19=reg34*pos_nodes[2][2]; reg31=reg4*pos_nodes[5][0];
    reg18=reg23-reg18; reg17=reg24-reg17; reg23=reg27*pos_nodes[5][2]; reg15=reg39-reg15; reg24=reg4*pos_nodes[5][2];
    reg35=reg36+reg35; reg36=reg26*pos_nodes[2][2]; reg37=reg27*pos_nodes[5][0]; reg14=reg21-reg14; reg21=var_inter[2]*reg1;
    reg39=reg34*pos_nodes[3][0]; T reg41=reg3*var_inter[2]; T reg42=reg34*pos_nodes[3][1]; reg30=reg33+reg30; reg9=reg25+reg9;
    reg25=reg2*pos_nodes[3][0]; reg33=reg10*pos_nodes[6][0]; reg28=reg32+reg28; reg32=reg41*pos_nodes[4][1]; T reg43=reg21*pos_nodes[4][1];
    T reg44=reg10*pos_nodes[6][2]; reg23=reg17-reg23; reg25=reg38+reg25; reg17=reg4*var_inter[2]; reg42=reg30-reg42;
    reg30=reg41*pos_nodes[4][0]; reg19=reg13+reg19; reg13=reg34*pos_nodes[3][2]; reg31=reg18+reg31; reg18=reg27*pos_nodes[6][2];
    reg39=reg9-reg39; reg9=reg21*pos_nodes[4][0]; reg38=reg2*pos_nodes[3][2]; reg36=reg35+reg36; reg35=reg27*pos_nodes[6][1];
    reg40=reg11-reg40; reg16=reg8+reg16; reg8=reg27*pos_nodes[6][0]; reg37=reg14-reg37; reg24=reg15+reg24;
    reg11=reg10*pos_nodes[6][1]; reg43=reg42-reg43; reg14=reg17*pos_nodes[5][0]; reg30=reg25+reg30; reg9=reg39-reg9;
    reg15=reg21*pos_nodes[5][0]; reg25=reg41*pos_nodes[4][2]; reg38=reg36+reg38; reg36=var_inter[1]*var_inter[2]; reg8=reg37+reg8;
    reg37=reg10*var_inter[2]; reg39=reg21*pos_nodes[5][1]; reg42=reg22*pos_nodes[7][2]; reg24=reg44+reg24; reg23=reg18+reg23;
    reg18=reg29*pos_nodes[7][2]; reg44=reg29*pos_nodes[7][0]; T reg45=reg17*pos_nodes[5][1]; reg32=reg28+reg32; reg33=reg31+reg33;
    reg28=reg22*pos_nodes[7][1]; reg11=reg16+reg11; reg13=reg19-reg13; reg16=reg21*pos_nodes[4][2]; reg19=reg22*pos_nodes[7][0];
    reg31=reg29*pos_nodes[7][1]; reg35=reg40+reg35; reg25=reg38+reg25; reg38=reg36*pos_nodes[6][1]; reg39=reg43+reg39;
    reg42=reg24+reg42; reg28=reg11+reg28; reg19=reg33+reg19; reg14=reg30+reg14; reg11=reg22*var_inter[2];
    reg44=reg8+reg44; reg31=reg35+reg31; reg8=reg37*pos_nodes[6][0]; reg24=reg21*pos_nodes[5][2]; reg16=reg13-reg16;
    reg15=reg9+reg15; reg9=reg36*pos_nodes[6][0]; reg13=reg17*pos_nodes[5][2]; reg30=reg37*pos_nodes[6][1]; reg18=reg23+reg18;
    reg45=reg32+reg45; reg23=reg28*reg18; reg32=reg44*reg42; reg33=reg19*reg18; reg35=reg31*reg42;
    reg13=reg25+reg13; reg8=reg14+reg8; reg14=pos_nodes[7][0]*reg11; reg25=reg36*pos_nodes[7][1]; reg9=reg15+reg9;
    reg24=reg16+reg24; reg15=reg36*pos_nodes[6][2]; reg16=reg11*pos_nodes[7][1]; reg30=reg45+reg30; reg40=reg36*pos_nodes[7][0];
    reg38=reg39+reg38; reg39=reg37*pos_nodes[6][2]; reg24=reg15+reg24; reg15=reg36*pos_nodes[7][2]; reg25=reg38-reg25;
    reg38=reg19*reg31; reg33=reg32-reg33; reg40=reg9-reg40; reg9=reg44*reg28; reg23=reg35-reg23;
    reg16=reg30+reg16; reg14=reg8+reg14; reg13=reg39+reg13; reg8=reg11*pos_nodes[7][2]; reg14=pos[0]-reg14;
    reg15=reg24-reg15; reg8=reg13+reg8; reg38=reg9-reg38; reg13=reg40*var_inter[0]; reg24=reg25*reg33;
    reg30=reg40*reg23; reg16=pos[1]-reg16; reg39=reg25*var_inter[0]; reg43=reg40*reg42; reg45=reg19*reg15;
    T reg46=reg31*reg15; T reg47=reg40*reg18; T reg48=reg44*reg15; T reg49=reg25*reg18; T reg50=reg28*reg15;
    T reg51=reg25*reg42; T reg52=reg15*var_inter[0]; T reg53=reg15*reg38; reg30=reg24-reg30; reg8=pos[2]-reg8;
    reg24=reg44*var_inter[1]; reg13=reg14+reg13; reg39=reg16+reg39; reg14=reg31*var_inter[1]; reg16=reg19*reg25;
    T reg54=reg40*reg28; reg48=reg47-reg48; T reg55=reg40*reg31; T reg56=reg44*reg25; reg39=reg14+reg39;
    reg45=reg43-reg45; reg52=reg8+reg52; reg46=reg49-reg46; reg8=reg28*var_inter[2]; reg13=reg24+reg13;
    reg50=reg51-reg50; reg53=reg30-reg53; reg14=reg18*var_inter[1]; reg24=reg19*var_inter[2]; reg30=reg42*var_inter[2];
    reg56=reg55-reg56; reg52=reg14+reg52; reg13=reg24+reg13; reg16=reg54-reg16; reg39=reg8+reg39;
    reg23=reg23/reg53; reg48=reg48/reg53; reg50=reg50/reg53; reg46=reg46/reg53; reg45=reg45/reg53;
    reg33=reg33/reg53; reg52=reg30+reg52; reg48=reg39*reg48; reg46=reg13*reg46; reg45=reg39*reg45;
    reg50=reg13*reg50; reg33=reg39*reg33; reg23=reg13*reg23; reg56=reg56/reg53; reg16=reg16/reg53;
    reg53=reg38/reg53; reg16=reg52*reg16; reg45=reg50-reg45; reg56=reg52*reg56; reg46=reg48-reg46;
    reg23=reg33-reg23; reg53=reg52*reg53; var_inter[1]=reg16+reg45; var_inter[0]=reg23-reg53; var_inter[2]=reg46-reg56;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Hexa &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[1]; T reg1=1-var_inter[2]; T reg2=1-var_inter[0]; T reg3=var_inter[0]*reg1; T reg4=reg2*reg1;
    T reg5=reg2*reg0; T reg6=var_inter[0]*reg0; T reg7=reg6*pos_nodes[1][1]; T reg8=pos_nodes[1][0]*reg6; T reg9=pos_nodes[0][0]*reg5;
    T reg10=pos_nodes[0][2]*reg4; T reg11=reg3*pos_nodes[1][2]; T reg12=pos_nodes[1][0]*reg3; T reg13=reg4*pos_nodes[0][0]; T reg14=pos_nodes[0][1]*reg5;
    T reg15=reg3*pos_nodes[1][1]; T reg16=pos_nodes[0][2]*reg5; T reg17=reg6*pos_nodes[1][2]; T reg18=pos_nodes[0][1]*reg4; T reg19=var_inter[0]*var_inter[1];
    T reg20=reg19*pos_nodes[2][2]; T reg21=reg3*pos_nodes[2][0]; reg12=reg13+reg12; reg11=reg10+reg11; reg10=reg3*pos_nodes[2][2];
    reg13=reg19*pos_nodes[2][0]; reg8=reg9+reg8; reg9=reg3*pos_nodes[2][1]; reg7=reg14+reg7; reg14=reg5*reg1;
    T reg22=reg19*pos_nodes[2][1]; reg15=reg18+reg15; reg18=reg6*reg1; reg17=reg16+reg17; reg16=reg2*var_inter[1];
    T reg23=reg1*reg0; T reg24=pos_nodes[3][2]*reg4; reg11=reg10-reg11; reg10=reg19*reg1; reg7=reg22+reg7;
    reg22=reg16*pos_nodes[3][1]; T reg25=var_inter[1]*reg1; reg8=reg13+reg8; reg13=reg16*pos_nodes[3][0]; T reg26=pos_nodes[1][0]*reg18;
    T reg27=reg14*pos_nodes[0][0]; T reg28=reg18*pos_nodes[1][1]; T reg29=reg14*pos_nodes[0][1]; reg17=reg20+reg17; reg20=reg16*pos_nodes[3][2];
    reg15=reg9-reg15; reg9=reg4*pos_nodes[3][1]; T reg30=reg2*var_inter[2]; T reg31=pos_nodes[0][1]*reg23; T reg32=reg23*pos_nodes[1][1];
    T reg33=reg4*pos_nodes[3][0]; reg12=reg21-reg12; reg21=pos_nodes[1][0]*reg23; T reg34=reg23*pos_nodes[0][0]; T reg35=pos_nodes[4][1]*reg30;
    reg22=reg7+reg22; reg31=reg32-reg31; reg9=reg15+reg9; reg7=reg25*pos_nodes[2][1]; reg1=reg16*reg1;
    reg15=reg23*pos_nodes[1][2]; reg26=reg27+reg26; reg27=pos_nodes[0][2]*reg14; reg32=reg18*pos_nodes[1][2]; T reg36=reg10*pos_nodes[2][0];
    T reg37=reg10*pos_nodes[2][1]; T reg38=pos_nodes[4][1]*reg5; reg20=reg17+reg20; reg17=pos_nodes[4][2]*reg5; T reg39=pos_nodes[4][2]*reg30;
    reg34=reg21-reg34; reg21=var_inter[0]*var_inter[2]; reg24=reg11+reg24; reg33=reg12+reg33; reg11=pos_nodes[4][0]*reg30;
    reg28=reg29+reg28; reg12=pos_nodes[0][2]*reg23; reg13=reg8+reg13; reg8=pos_nodes[4][0]*reg5; reg29=reg25*pos_nodes[2][0];
    T reg40=pos_nodes[5][1]*reg21; reg35=reg9-reg35; reg12=reg15-reg12; reg9=reg6*pos_nodes[5][2]; reg22=reg38-reg22;
    reg15=reg10*pos_nodes[2][2]; reg20=reg17-reg20; reg17=reg1*pos_nodes[3][1]; reg28=reg37+reg28; reg39=reg24-reg39;
    reg24=pos_nodes[5][2]*reg21; reg37=reg6*pos_nodes[5][1]; reg32=reg27+reg32; reg27=reg25*pos_nodes[2][2]; reg38=reg25*pos_nodes[3][0];
    T reg41=var_inter[2]*reg5; reg34=reg29+reg34; reg13=reg8-reg13; reg8=pos_nodes[5][0]*reg21; reg31=reg7+reg31;
    reg7=reg25*pos_nodes[3][1]; reg29=reg6*pos_nodes[5][0]; T reg42=var_inter[2]*reg0; reg11=reg33-reg11; reg26=reg36+reg26;
    reg33=reg1*pos_nodes[3][0]; reg37=reg22+reg37; reg22=pos_nodes[6][0]*reg21; reg36=reg19*pos_nodes[6][1]; reg38=reg34-reg38;
    reg34=pos_nodes[4][0]*reg42; reg8=reg11-reg8; reg11=reg19*pos_nodes[6][0]; reg29=reg13+reg29; reg17=reg28+reg17;
    reg13=reg41*pos_nodes[4][1]; reg24=reg39-reg24; reg28=pos_nodes[6][2]*reg21; reg39=reg6*var_inter[2]; T reg43=pos_nodes[4][1]*reg42;
    reg7=reg31-reg7; reg31=pos_nodes[3][2]*reg25; reg12=reg27+reg12; reg27=reg1*pos_nodes[3][2]; reg40=reg35-reg40;
    reg35=pos_nodes[6][1]*reg21; reg32=reg15+reg32; reg15=reg19*pos_nodes[6][2]; reg9=reg20+reg9; reg20=reg41*pos_nodes[4][0];
    reg33=reg26+reg33; reg22=reg8+reg22; reg8=pos_nodes[7][0]*reg30; reg28=reg24+reg28; reg24=reg30*pos_nodes[7][2];
    reg26=pos_nodes[5][0]*reg42; reg34=reg38-reg34; reg38=var_inter[1]*var_inter[2]; reg15=reg9+reg15; reg9=reg16*pos_nodes[7][2];
    reg27=reg32+reg27; reg32=reg41*pos_nodes[4][2]; T reg44=reg19*var_inter[2]; reg11=reg29+reg11; reg29=reg16*pos_nodes[7][0];
    reg13=reg17+reg13; reg17=reg39*pos_nodes[5][1]; T reg45=reg16*pos_nodes[7][1]; reg36=reg37+reg36; reg20=reg33+reg20;
    reg33=reg39*pos_nodes[5][0]; reg37=reg30*pos_nodes[7][1]; reg35=reg40+reg35; reg31=reg12-reg31; reg43=reg7-reg43;
    reg7=pos_nodes[5][1]*reg42; reg12=pos_nodes[4][2]*reg42; reg37=reg35+reg37; reg9=reg15+reg9; reg15=reg44*pos_nodes[6][0];
    reg33=reg20+reg33; reg32=reg27+reg32; reg20=reg39*pos_nodes[5][2]; reg45=reg36+reg45; reg7=reg43+reg7;
    reg27=reg16*var_inter[2]; reg29=reg11+reg29; reg11=pos_nodes[6][1]*reg38; reg12=reg31-reg12; reg31=pos_nodes[5][2]*reg42;
    reg8=reg22+reg8; reg22=reg44*pos_nodes[6][1]; reg26=reg34+reg26; reg34=pos_nodes[6][0]*reg38; reg24=reg28+reg24;
    reg17=reg13+reg17; reg34=reg26+reg34; reg11=reg7+reg11; reg7=reg38*pos_nodes[7][1]; reg31=reg12+reg31;
    reg12=pos_nodes[6][2]*reg38; reg13=reg29*reg24; reg26=reg8*reg9; reg28=reg45*reg24; reg35=reg37*reg9;
    reg36=reg44*pos_nodes[6][2]; reg20=reg32+reg20; reg32=pos_nodes[7][0]*reg38; reg22=reg17+reg22; reg17=reg27*pos_nodes[7][0];
    reg15=reg33+reg15; reg33=reg27*pos_nodes[7][1]; reg32=reg34-reg32; reg7=reg11-reg7; reg12=reg31+reg12;
    reg11=reg29*reg37; reg13=reg26-reg13; reg33=reg22+reg33; reg22=reg8*reg45; reg28=reg35-reg28;
    reg31=reg27*pos_nodes[7][2]; reg36=reg20+reg36; reg20=reg38*pos_nodes[7][2]; reg17=reg15+reg17; reg15=reg7*reg13;
    reg34=var_inter[0]*reg32; reg33=pos[1]-reg33; reg40=reg32*reg28; reg11=reg22-reg11; reg31=reg36+reg31;
    reg36=var_inter[0]*reg7; reg17=pos[0]-reg17; reg20=reg12-reg20; reg12=reg7*reg9; reg43=reg20*reg11;
    T reg46=reg45*reg20; reg40=reg15-reg40; reg15=reg7*reg24; T reg47=reg37*reg20; T reg48=reg8*reg20;
    T reg49=var_inter[1]*reg8; reg34=reg17+reg34; reg17=reg32*reg24; reg31=pos[2]-reg31; T reg50=reg32*reg9;
    T reg51=var_inter[0]*reg20; T reg52=reg29*reg20; reg36=reg33+reg36; reg33=var_inter[1]*reg37; T reg53=reg8*reg7;
    T reg54=reg32*reg37; T reg55=reg29*reg7; T reg56=reg32*reg45; reg48=reg17-reg48; reg34=reg49+reg34;
    reg36=reg33+reg36; reg33=var_inter[1]*reg24; reg51=reg31+reg51; reg52=reg50-reg52; reg31=var_inter[2]*reg45;
    reg49=var_inter[2]*reg29; reg47=reg15-reg47; reg43=reg40-reg43; reg46=reg12-reg46; reg34=reg49+reg34;
    reg47=reg47/reg43; reg40=var_inter[2]*reg9; reg36=reg31+reg36; reg13=reg13/reg43; reg46=reg46/reg43;
    reg48=reg48/reg43; reg51=reg33+reg51; reg52=reg52/reg43; reg28=reg28/reg43; reg55=reg56-reg55;
    reg53=reg54-reg53; reg55=reg55/reg43; reg53=reg53/reg43; reg28=reg34*reg28; reg43=reg11/reg43;
    reg13=reg13*reg36; reg51=reg40+reg51; reg46=reg34*reg46; reg48=reg36*reg48; reg47=reg34*reg47;
    reg52=reg52*reg36; reg28=reg13-reg28; reg47=reg48-reg47; reg43=reg51*reg43; reg53=reg51*reg53;
    reg52=reg46-reg52; reg55=reg51*reg55; var_inter[0]+=reg28-reg43; var_inter[2]+=reg47-reg53; var_inter[1]+=reg55+reg52;

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
