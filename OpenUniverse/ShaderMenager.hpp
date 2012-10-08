#include <GL\glew.h>
#include <glm\glm.hpp>

#ifndef SHADER_H
#define SHADER_H
class Shader 
{
public:
    Shader(); 
    Shader(const char *vsFile, const char *fsFile); 
    ~Shader();
    
    void init(const char *vsFile, const char *fsFile);
	void BindAtributs(const char *name);

	void SetUniform(const char* name,const glm::vec3 &v);
	void SetUniform(const char* name,const glm::vec4 &v);

	void SetUniform(const char* name,const glm::mat3 &m);
	void SetUniform(const char* name,const glm::mat4 &m);

	void SetUniform(const char* name,bool b);
	void SetUniform(const char* name,float f);
	void SetUniform(const char* name,int i);

	unsigned int getUniformLocation(const char * name );


    void bind(); 
    void unbind(); 

    
    unsigned int id(); // Get the identifier for our program
    
private:
    unsigned int shader_id; 
    unsigned int shader_vp; 
    unsigned int shader_fp; 
    bool inited; 
};
#endif