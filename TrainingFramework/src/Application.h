#pragma once
#include "Singleton.h"
#include "GameConfig.h"
#include "soloud.h"
#include "stdlib.h" 
#include "soloud_wav.h"


class Application : public CSingleton<Application>
{
public:
	Application();
	~Application();
	void		Init();
	void		Update( GLfloat deltaTime);
	void		Render();
	void		HandleKeyEvent(unsigned char key, bool bIsPresseded);
	void		HandleTouchEvent(GLint x, GLint y, bool bIsPresseded);
	void		Exit();


	SoLoud::Soloud soloud;

private:	

};

