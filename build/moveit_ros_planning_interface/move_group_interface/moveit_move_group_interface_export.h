
#ifndef MOVEIT_MOVE_GROUP_INTERFACE_EXPORT_H
#define MOVEIT_MOVE_GROUP_INTERFACE_EXPORT_H

#ifdef MOVEIT_MOVE_GROUP_INTERFACE_STATIC_DEFINE
#  define MOVEIT_MOVE_GROUP_INTERFACE_EXPORT
#  define MOVEIT_MOVE_GROUP_INTERFACE_NO_EXPORT
#else
#  ifndef MOVEIT_MOVE_GROUP_INTERFACE_EXPORT
#    ifdef moveit_move_group_interface_EXPORTS
        /* We are building this library */
#      define MOVEIT_MOVE_GROUP_INTERFACE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MOVEIT_MOVE_GROUP_INTERFACE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MOVEIT_MOVE_GROUP_INTERFACE_NO_EXPORT
#    define MOVEIT_MOVE_GROUP_INTERFACE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED
#  define MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED_EXPORT
#  define MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED_EXPORT MOVEIT_MOVE_GROUP_INTERFACE_EXPORT MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED
#endif

#ifndef MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED_NO_EXPORT
#  define MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED_NO_EXPORT MOVEIT_MOVE_GROUP_INTERFACE_NO_EXPORT MOVEIT_MOVE_GROUP_INTERFACE_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MOVEIT_MOVE_GROUP_INTERFACE_NO_DEPRECATED
#    define MOVEIT_MOVE_GROUP_INTERFACE_NO_DEPRECATED
#  endif
#endif

#endif /* MOVEIT_MOVE_GROUP_INTERFACE_EXPORT_H */
