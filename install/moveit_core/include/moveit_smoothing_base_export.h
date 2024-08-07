
#ifndef MOVEIT_SMOOTHING_BASE_EXPORT_H
#define MOVEIT_SMOOTHING_BASE_EXPORT_H

#ifdef MOVEIT_SMOOTHING_BASE_STATIC_DEFINE
#  define MOVEIT_SMOOTHING_BASE_EXPORT
#  define MOVEIT_SMOOTHING_BASE_NO_EXPORT
#else
#  ifndef MOVEIT_SMOOTHING_BASE_EXPORT
#    ifdef moveit_smoothing_base_EXPORTS
        /* We are building this library */
#      define MOVEIT_SMOOTHING_BASE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MOVEIT_SMOOTHING_BASE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MOVEIT_SMOOTHING_BASE_NO_EXPORT
#    define MOVEIT_SMOOTHING_BASE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MOVEIT_SMOOTHING_BASE_DEPRECATED
#  define MOVEIT_SMOOTHING_BASE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MOVEIT_SMOOTHING_BASE_DEPRECATED_EXPORT
#  define MOVEIT_SMOOTHING_BASE_DEPRECATED_EXPORT MOVEIT_SMOOTHING_BASE_EXPORT MOVEIT_SMOOTHING_BASE_DEPRECATED
#endif

#ifndef MOVEIT_SMOOTHING_BASE_DEPRECATED_NO_EXPORT
#  define MOVEIT_SMOOTHING_BASE_DEPRECATED_NO_EXPORT MOVEIT_SMOOTHING_BASE_NO_EXPORT MOVEIT_SMOOTHING_BASE_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MOVEIT_SMOOTHING_BASE_NO_DEPRECATED
#    define MOVEIT_SMOOTHING_BASE_NO_DEPRECATED
#  endif
#endif

#endif /* MOVEIT_SMOOTHING_BASE_EXPORT_H */
