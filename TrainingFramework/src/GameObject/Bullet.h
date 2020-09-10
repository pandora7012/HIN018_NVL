#include "Sprite2D.h"
#include "Slime.h"


class Bullet : public Sprite2D {

public:
	Bullet();
	Bullet(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	

	int getDmg();
	void Update(GLfloat deltaTime) override; 

	void setDmg(int dmg); 
	bool checkCollision(std::shared_ptr<Slime> slime);


private:
	int m_dmg;

};