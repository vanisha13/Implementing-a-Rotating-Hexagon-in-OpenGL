#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture {
public:
    Texture(const char* texturePath);
    void bind() const;
    GLuint getID() const;
    // Other methods...

private:
    GLuint ID;
};

#endif // TEXTURE_H
