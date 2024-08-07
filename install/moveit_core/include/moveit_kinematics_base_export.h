
#ifndef MOVEIT_KINEMATICS_BASE_EXPORT_H
#define MOVEIT_KINEMATICS_BASE_EXPORT_H

#ifdef MOVEIT_KINEMATICS_BASE_STATIC_DEFINE
#  define MOVEIT_KINEMATICS_BASE_EXPORT
#  define MOVEIT_KINEMATICS_BASE_NO_EXPORT
#else
#  ifndef MOVEIT_KINEMATICS_BASE_EXPORT
#    ifdef moveit_kinematics_base_EXPORTS
        /* We are building this library */
#      define MOVEIT_KINEMATICS_BASE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MOVEIT_KINEMATICS_BASE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MOVEIT_KINEMATICS_BASE_NO_EXPORT
#    define MOVEIT_KINEMATICS_BASE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MOVEIT_KINEMATICS_BASE_DEPRECATED
#  define MOVEIT_KINEMATICS_BASE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MOVEIT_KINEMATICS_BASE_DEPRECATED_EXPORT
#  define MOVEIT_KINEMATICS_BASE_DEPRECATED_EXPORT MOVEIT_KINEMATICS_BASE_EXPORT MOVEIT_KINEMATICS_BASE_DEPRECATED
#endif

#ifndef MOVEIT_KINEMATICS_BASE_DEPRECATED_NO_EXPORT
#  define MOVEIT_KINEMATICS_BASE_DEPRECATED_NO_EXPORT MOVEIT_KINEMATICS_BASE_NO_EXPORT MOVEIT_KINEMATICS_BASE_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MOVEIT_KINEMATICS_BASE_NO_DEPRECATED
#    define MOVEIT_KINEMATICS_BASE_NO_DEPRECATED
#  endif
#endif

#endif /* MOVEIT_KINEMATICS_BASE_EXPORT_H */
