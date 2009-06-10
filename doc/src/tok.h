#ifndef TOK_H
#define TOK_H
#include "nstring.h"

#include "config.h"

namespace Tok {
    enum {
        END_TOK_FILE,
        PUSH_ROOM_FOR_NEW_VARIABLE,
        CHECK_ROOM_IN_VARIABLE_STACK,
        VARIABLE_NAMED,
        VARIABLE_IN_STACK,
        VARIABLE_IN_ARGS,
        GET_ATTR,
        SELF,
        INTERACT,
        CONSTIFY,
        ASSIGN__CALCULATED_NAME_0__TYPE_0__NEED_VERIFICATION_0,
        ASSIGN__CALCULATED_NAME_1__TYPE_0__NEED_VERIFICATION_0,
        ASSIGN__CALCULATED_NAME_0__TYPE_1__NEED_VERIFICATION_0,
        ASSIGN__CALCULATED_NAME_1__TYPE_1__NEED_VERIFICATION_0,
        ASSIGN__CALCULATED_NAME_0__TYPE_0__NEED_VERIFICATION_1,
        ASSIGN__CALCULATED_NAME_1__TYPE_0__NEED_VERIFICATION_1,
        ASSIGN__CALCULATED_NAME_0__TYPE_1__NEED_VERIFICATION_1,
        ASSIGN__CALCULATED_NAME_1__TYPE_1__NEED_VERIFICATION_1,
        APPLY,
        SELECT,
        CHANGE_BEHAVIOR,
        PARTIAL_INSTANCIATION,
        APPEND_INHERITANCE_DATA,
        TEST_NEXT_TYPE,
        PASS,
        IMPORT,
        EXEC,
        THROW,
        TRY,
        CATCH,
        END_CATCH_BLOCK,
        END_TRY_EXCEPTION_BLOCK,
        GET_CALCULATED_ATTR,
        GET_VALUE_PROP,
        NUMBER,
        NUMBER_INT32,
        NUMBER_UNSIGNED32,
        STRING,
        AND_OR_OR__WANT_OR_0,
        AND_OR_OR__WANT_OR_1,
        CONVERSION_TO_BOOL,
        IF_OR_WHILE__WANT_WHILE_0,
        IF_OR_WHILE__WANT_WHILE_1,
        END_OF_AN_IF_BLOCK,
        END_OF_A_WHILE_BLOCK__IN_ELSE_BLOCK_0,
        END_OF_A_WHILE_BLOCK__IN_ELSE_BLOCK_1,
        END_OF_AN_IF_BLOCK_FOLLOWED_BY_AN_ELSE,
        END_OF_A_WHILE_BLOCK_FOLLOWED_BY_AN_ELSE,
        FOR__WANT_TUPLE_0,
        FOR__WANT_TUPLE_1,
        END_OF_A_FOR_BLOCK,
        LAMBDA,
        LABEL,
        END_OF_A_LABEL_BLOCK,
        DEF_RETURN,
        BREAK_OR_CONTINUE__WANT_CONTINUE_0,
        BREAK_OR_CONTINUE__WANT_CONTINUE_1,
        MAKE_VARARGS__EXPECT_RESULT_0,
        MAKE_VARARGS__EXPECT_RESULT_1,
        DEFINITION,
        PROPOSITION_OF_DEFAULT_VALUE,
        ASSIGN_TO_ARG_NB,
        END_CLASS_BLOCK,
        END_DEF_BLOCK,
        END_TRY_BLOCK,
        CONDITION_IN_TRY_BLOCK,
        PERTINENCE_IN_TRY_BLOCK,
        EXEC_IN_PREV_SCOPE,
        END_EXEC_IN_PREV_SCOPE,
    };
    inline int get_ASSIGN_type(int calculated_name,int type,int need_verification) {
        if ( calculated_name==0 and type==0 and need_verification==0 ) return ASSIGN__CALCULATED_NAME_0__TYPE_0__NEED_VERIFICATION_0;
        if ( calculated_name==1 and type==0 and need_verification==0 ) return ASSIGN__CALCULATED_NAME_1__TYPE_0__NEED_VERIFICATION_0;
        if ( calculated_name==0 and type==1 and need_verification==0 ) return ASSIGN__CALCULATED_NAME_0__TYPE_1__NEED_VERIFICATION_0;
        if ( calculated_name==1 and type==1 and need_verification==0 ) return ASSIGN__CALCULATED_NAME_1__TYPE_1__NEED_VERIFICATION_0;
        if ( calculated_name==0 and type==0 and need_verification==1 ) return ASSIGN__CALCULATED_NAME_0__TYPE_0__NEED_VERIFICATION_1;
        if ( calculated_name==1 and type==0 and need_verification==1 ) return ASSIGN__CALCULATED_NAME_1__TYPE_0__NEED_VERIFICATION_1;
        if ( calculated_name==0 and type==1 and need_verification==1 ) return ASSIGN__CALCULATED_NAME_0__TYPE_1__NEED_VERIFICATION_1;
        if ( calculated_name==1 and type==1 and need_verification==1 ) return ASSIGN__CALCULATED_NAME_1__TYPE_1__NEED_VERIFICATION_1;
        return 0;
    }
    inline int get_AND_OR_OR_type(int want_or) {
        if ( want_or==0 ) return AND_OR_OR__WANT_OR_0;
        if ( want_or==1 ) return AND_OR_OR__WANT_OR_1;
        return 0;
    }
    inline int get_IF_OR_WHILE_type(int want_while) {
        if ( want_while==0 ) return IF_OR_WHILE__WANT_WHILE_0;
        if ( want_while==1 ) return IF_OR_WHILE__WANT_WHILE_1;
        return 0;
    }
    inline int get_END_OF_A_WHILE_BLOCK_type(int in_else_block) {
        if ( in_else_block==0 ) return END_OF_A_WHILE_BLOCK__IN_ELSE_BLOCK_0;
        if ( in_else_block==1 ) return END_OF_A_WHILE_BLOCK__IN_ELSE_BLOCK_1;
        return 0;
    }
    inline int get_FOR_type(int want_tuple) {
        if ( want_tuple==0 ) return FOR__WANT_TUPLE_0;
        if ( want_tuple==1 ) return FOR__WANT_TUPLE_1;
        return 0;
    }
    inline int get_BREAK_OR_CONTINUE_type(int want_continue) {
        if ( want_continue==0 ) return BREAK_OR_CONTINUE__WANT_CONTINUE_0;
        if ( want_continue==1 ) return BREAK_OR_CONTINUE__WANT_CONTINUE_1;
        return 0;
    }
    inline int get_MAKE_VARARGS_type(int expect_result) {
        if ( expect_result==0 ) return MAKE_VARARGS__EXPECT_RESULT_0;
        if ( expect_result==1 ) return MAKE_VARARGS__EXPECT_RESULT_1;
        return 0;
    }
    struct End_tok_file {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Push_room_for_new_variable {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Check_room_in_variable_stack {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        unsigned nb_variables;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Variable_named {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        Nstring name;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Variable_in_stack {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_in_nb_variables;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Variable_in_args {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int num_arg;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Get_attr {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        Nstring name;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Self {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Interact {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Constify {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Assign {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned STATIC = 1;  bool has_attr_static() const { return attributes & 1; }
        static const unsigned CONST = 2;  bool has_attr_const() const { return attributes & 2; }
        static const unsigned VIRTUAL = 4;  bool has_attr_virtual() const { return attributes & 4; }
        static const unsigned WANT_REF = 8;  bool has_attr_want_ref() const { return attributes & 8; }
        static const unsigned PROPERTY = 16;  bool has_attr_property() const { return attributes & 16; }

        unsigned attributes;
        int offset_to_doc;
        Nstring name;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Apply {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned EXPECT_RES = 1;  bool has_attr_expect_res() const { return attributes & 1; }

        unsigned attributes;
        unsigned nb_unnamed;
        unsigned nb_named;
        Nstring named[1];

        const Nstring *get_first_named() const { return reinterpret_cast<const Nstring *>(named); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*named); return reinterpret_cast<const void *>( &named + ( (nb_named+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Select {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned EXPECT_RES = 1;  bool has_attr_expect_res() const { return attributes & 1; }

        unsigned attributes;
        unsigned nb_unnamed;
        unsigned nb_named;
        Nstring named[1];

        const Nstring *get_first_named() const { return reinterpret_cast<const Nstring *>(named); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*named); return reinterpret_cast<const void *>( &named + ( (nb_named+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Change_behavior {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned EXPECT_RES = 1;  bool has_attr_expect_res() const { return attributes & 1; }

        unsigned attributes;
        unsigned nb_unnamed;
        unsigned nb_named;
        Nstring named[1];

        const Nstring *get_first_named() const { return reinterpret_cast<const Nstring *>(named); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*named); return reinterpret_cast<const void *>( &named + ( (nb_named+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Partial_instanciation {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Append_inheritance_data {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Test_next_type {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Pass {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Import {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Exec {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Throw {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Try {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_next_inst;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct Catch {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        Nstring arg;
        int offset_to_next_inst;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct End_catch_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_try_exception_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Get_calculated_attr {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Get_value_prop {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Number {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned UNSIGNED = 1;  bool has_attr_unsigned() const { return attributes & 1; }
        static const unsigned IMAGINARY = 2;  bool has_attr_imaginary() const { return attributes & 2; }

        unsigned attributes;
        int expo;
        unsigned nb_values;
        unsigned values[1];

        const unsigned *get_first_values() const { return reinterpret_cast<const unsigned *>(values); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*values); return reinterpret_cast<const void *>( &values + ( (nb_values+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Number_int32 {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        Int32 val;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Number_unsigned32 {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        Unsigned32 val;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct String {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        unsigned nb_characters;
        char characters[1];

        const char *get_first_characters() const { return reinterpret_cast<const char *>(characters); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*characters); return reinterpret_cast<const void *>( &characters + ( (nb_characters+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct And_or_or {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_if_dont_want_to_continue;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_if_dont_want_to_continue); }
    };
    struct Conversion_to_bool {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct If_or_while {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_if_fail;
        int offset_if_not_executed;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_if_not_executed); }
    };
    struct End_of_an_if_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_of_a_while_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_condition;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_of_an_if_block_followed_by_an_else {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_next_inst;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct End_of_a_while_block_followed_by_an_else {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_condition;
        int offset_to_next_inst;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct For {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_next_inst;
        unsigned nb_names;
        Nstring names[1];

        const Nstring *get_first_names() const { return reinterpret_cast<const Nstring *>(names); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*names); return reinterpret_cast<const void *>( &names + ( (nb_names+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct End_of_a_for_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Lambda {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_next_inst;
        unsigned nb_arguments;
        Nstring arguments[1];

        const Nstring *get_first_arguments() const { return reinterpret_cast<const Nstring *>(arguments); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*arguments); return reinterpret_cast<const void *>( &arguments + ( (nb_arguments+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct Label {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        int offset_to_next_inst;
        Nstring name;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct End_of_a_label_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Def_return {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Break_or_continue {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Make_varargs {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        unsigned nb_unnamed_children;
        unsigned nb_names;
        Nstring names[1];

        const Nstring *get_first_names() const { return reinterpret_cast<const Nstring *>(names); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*names); return reinterpret_cast<const void *>( &names + ( (nb_names+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Definition {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        static const unsigned CLASS = 1;  bool has_attr_class() const { return attributes & 1; }
        static const unsigned STATIC = 2;  bool has_attr_static() const { return attributes & 2; }
        static const unsigned VIRTUAL = 4;  bool has_attr_virtual() const { return attributes & 4; }
        static const unsigned VARARGS = 8;  bool has_attr_varargs() const { return attributes & 8; }
        static const unsigned SELF_AS_ARG = 16;  bool has_attr_self_as_arg() const { return attributes & 16; }
        static const unsigned ABSTRACT = 32;  bool has_attr_abstract() const { return attributes & 32; }
        static const unsigned METHOD = 64;  bool has_attr_method() const { return attributes & 64; }

        unsigned attributes;
        Nstring name;
        int offset_to_doc;
        unsigned size_needed_in_stack;
        Float64 pertinence;
        unsigned min_nb_args;
        Nstring property_name;
        unsigned type_property;
        int offset_to_try_block;
        int offset_to_block;
        int offset_to_next_inst;
        unsigned nb_args;
        Nstring args[1];

        const Nstring *get_first_args() const { return reinterpret_cast<const Nstring *>(args); }
        const void *next() const { const unsigned o = (sizeof(unsigned)-1)/sizeof(*args); return reinterpret_cast<const void *>( &args + ( (nb_args+o) & ~o ) ); }
        const void *next_in_exception_mode() const { return reinterpret_cast<const void *>(reinterpret_cast<const char *>(this) + offset_to_next_inst); }
    };
    struct Proposition_of_default_value {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        unsigned num_arg;
        int offset_to_next_inst;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Assign_to_arg_nb {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        unsigned num_arg;
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_class_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_def_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_try_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Condition_in_try_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Pertinence_in_try_block {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct Exec_in_prev_scope {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    struct End_exec_in_prev_scope {
        unsigned type; /// VARIABLE, DEFINITION...
        unsigned offset_in_sar_file; /// pos in original source file
        const void *next() const { return reinterpret_cast<const void *>( this + 1 ); }
        const void *next_in_exception_mode() const { return next(); }
    };
    void disp(std::ostream &os,const void *tok);
    const void *get_next(const void *tok);
    const void *get_next_in_exception_mode(const void *tok);
} // namespace

inline unsigned num_primitive(const std::string &type) {
    if ( type == "Def" ) return 0;
    if ( type == "Error" ) return 1;
    if ( type == "Bool" ) return 2;
    if ( type == "Unsigned8" ) return 3;
    if ( type == "Unsigned16" ) return 4;
    if ( type == "Unsigned32" ) return 5;
    if ( type == "Unsigned64" ) return 6;
    if ( type == "Int8" ) return 7;
    if ( type == "Int16" ) return 8;
    if ( type == "Int32" ) return 9;
    if ( type == "Int64" ) return 10;
    if ( type == "Rationnal" ) return 11;
    if ( type == "Float32" ) return 12;
    if ( type == "Float64" ) return 13;
    if ( type == "Float96" ) return 14;
    if ( type == "Void" ) return 15;
    if ( type == "BlockOfTok" ) return 16;
    if ( type == "CFile" ) return 17;
    if ( type == "UntypedPtr" ) return 18;
    if ( type == "Property" ) return 19;
    if ( type == "VarArgs" ) return 20;
    if ( type == "InternalVariable" ) return 21;
    if ( type == "Functionnal" ) return 22;
    if ( type == "Op" ) return 23;
    if ( type == "CodeWriter_" ) return 24;
    if ( type == "CodeWriterAlt_" ) return 25;
    if ( type == "Lambda" ) return 26;
    if ( type == "Label" ) return 27;
    if ( type == "CompiledFunctionSet_" ) return 28;
    if ( type == "DlLoader" ) return 29;
    if ( type == "Pthread" ) return 30;
    if ( type == "Semaphore" ) return 31;
    std::cerr << "internal error : not a primitive " << type << std::endl; return 0;
}

#endif // TOK_H
