#include <glad/glad.h>
#include <GLFW/glfw3.h>
GLvoid VersionInfo()
{
	const GLubyte* name = glGetString(GL_VENDOR);            //���ظ���ǰOpenGLʵ�ֳ��̵�����
	const GLubyte* biaoshifu = glGetString(GL_RENDERER);    //����һ����Ⱦ����ʶ����ͨ���Ǹ�Ӳ��ƽ̨
	const GLubyte* OpenGLVersion = glGetString(GL_VERSION);    //���ص�ǰOpenGLʵ�ֵİ汾��
	const GLubyte* glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);//������ɫԤѹ�������汾��
	printf("OpenGLʵ�ֳ��̵����֣�%s\n", name);
	printf("��Ⱦ����ʶ����%s\n", biaoshifu);
	printf("OpenGLʵ�ֵİ汾�ţ�%s\n", OpenGLVersion);
	printf("OpenGL��ɫ���԰汾��%s\n", glsl);
}