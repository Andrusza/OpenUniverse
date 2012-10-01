#include <GL\glew.h>
#include <glm\glm.hpp>

#ifndef SHADER_H
#define SHADER_H
class Shader 
{
public:
    Shader(); // Default constructor
    Shader(const char *vsFile, const char *fsFile); // Constructor for creating a shader from two shader filenames
    ~Shader(); // Deconstructor for cleaning up
    
    void init(const char *vsFile, const char *fsFile); // Initialize our shader file if we have to
	void BindAtributs(const char *name);

	void SetUniform(const char* name,const glm::vec3 &v);
	void SetUniform(const char* name,const glm::vec4 &v);

	void SetUniform(const char* name,const glm::mat3 &m);
	void SetUniform(const char* name,const glm::mat4 &m);

	void SetUniform(const char* name,bool b);
	void SetUniform(const char* name,float f);
	void SetUniform(const char* name,int i);


    void bind(); // Bind our GLSL shader program
    void unbind(); // Unbind our GLSL shader program

    
    unsigned int id(); // Get the identifier for our program
    
private:
    unsigned int shader_id; // The shader program identifier
    unsigned int shader_vp; // The vertex shader identifier
    unsigned int shader_fp; // The fragment shader identifier
    bool inited; // Whether or not we have initialized the shader
	unsigned int getUniformLocation(const char * name );

};
#endif