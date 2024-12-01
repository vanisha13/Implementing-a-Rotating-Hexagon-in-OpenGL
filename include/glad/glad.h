#ifndef GLAD_H
#define GLAD_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef void* (*GLADloadproc)(const char* name);

	int gladLoadGLLoader(GLADloadproc proc);

#ifdef __cplusplus
}
#endif

#endif /* GLAD_H */
