#include "Sprite2D.h"


class Monster;

class Bullet : public Sprite2D {

public:
	Bullet();
	Bullet(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	

	int getDmg();
	void Update(GLfloat deltaTime) override; 

	
	bool checkCollision(std::shared_ptr<Monster> monster);



private:
	int dmg;
};