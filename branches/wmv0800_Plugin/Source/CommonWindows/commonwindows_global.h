#ifndef COMMONWINDOWS_GLOBAL_H
#define COMMONWINDOWS_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef COMMONWINDOWS_LIB
# define COMMONWINDOWS_EXPORT Q_DECL_EXPORT
#else
# define COMMONWINDOWS_EXPORT Q_DECL_IMPORT
#endif

#endif //COMMONWINDOWS_GLOBAL_H
