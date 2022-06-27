/**
 * @file exports.h
 * @author おり (kok.in@yahoo.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) ori-d <おり> 2022
 * 
 */

#ifndef ODIN_net_EXPORTS_H
#define ODIN_net_EXPORTS_H 1

#if defined _WIN32 || defined __CYGWIN__ && !defined __GNUC__
  #define odin_net_helper_import __declspec(dllimport)
  #define odin_net_helper_export __declspec(dllexport)
  #define odin_net_helper_local
#else
  #if __GNUC__ >= 4
    #define odin_net_helper_import __attribute__ ((visibility ("default")))
    #define odin_net_helper_export __attribute__ ((visibility ("default")))
    #define odin_net_helper_local  __attribute__ ((visibility ("hidden")))
  #else
    #define odin_net_helper_import 
    #define odin_net_helper_export 
    #define odin_net_helper_local 
  #endif
#endif

#ifdef odin_net_dll
  #ifdef odin_net_dll_exports
    #define odin_net_api odin_net_helper_export
  #else
    #define odin_net_api odin_net_helper_import
  #endif
  #define odin_net_local odin_net_helper_local
#else
  #define odin_net_api 
  #define odin_net_local 
#endif

#endif /* ODIN_NET_CONFIG_H */
