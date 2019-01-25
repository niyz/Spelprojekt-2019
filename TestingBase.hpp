#ifndef TESTING_BASE_HPP
#define TESTING_BASE_HPP
/*******************************************************************
*						Here be Dragons
********************************************************************/

#include <type_traits>
#include <functional>
#include <cctype>
#include <cstdint>

#define GENERATE_HAS_MEMBER_FUNCTION(functionName, memberFunction)                    \
    template <typename T, typename RESULT, typename... ARGS>                          \
    class has_##functionName                                                          \
    {                                                                                 \
        typedef std::true_type yes;                                                   \
        typedef std::false_type no;                                                   \
        template <typename U, RESULT (U::*)(ARGS...)>                                 \
        struct Check;                                                                 \
        template <typename U>                                                         \
        static yes func(Check<U, &U::memberFunction> *);                              \
        template <typename>                                                           \
        static no func(...);                                                          \
                                                                                      \
      public:                                                                         \
        typedef has_##functionName type;                                              \
        static constexpr bool value = std::is_same<decltype(func<T>(0)), yes>::value; \
    };

#define GENERATE_HAS_CONST_MEMBER_FUNCTION(functionName, memberFunction)              \
    template <typename T, typename RESULT, typename... ARGS>                          \
    class has_const_##functionName                                                    \
    {                                                                                 \
        typedef std::true_type yes;                                                   \
        typedef std::false_type no;                                                   \
        template <typename U, RESULT (U::*)(ARGS...) const>                           \
        struct Check;                                                                 \
        template <typename U>                                                         \
        static yes func(Check<U, &U::memberFunction> *);                              \
        template <typename>                                                           \
        static no func(...);                                                          \
                                                                                      \
      public:                                                                         \
        typedef has_const_##functionName type;                                        \
        static constexpr bool value = std::is_same<decltype(func<T>(0)), yes>::value; \
    };

#define GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(name) GENERATE_HAS_MEMBER_FUNCTION(name, name)
#define GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(name) GENERATE_HAS_CONST_MEMBER_FUNCTION(name, name)

/*
* 
*   Usage:
*       GENERATE_HAS_MEMBER_FUNCTION(generatedName, functionName) creates a template-based struct.
*       This struct can then be used as: has_generatedName<ClassToCheck, ExpectedReturnType, ArgType1, ArgType2,...>::value.       
*       If this value is true, then the ClassToCheck has a member method named functionName that matches the signature given.
*       The args can be empty.
*       To check for const functions, GENERATE_HAS_CONST_MEMBER_FUNCTION must be used.
*       For same generatedName and functionName, use GENERATE_SAME_NAME_HAS...
* 
*   Important!
*       This code will not be able to check for constructor, use is_constructible for this!
* 
* 
* 
* 
*/
#endif