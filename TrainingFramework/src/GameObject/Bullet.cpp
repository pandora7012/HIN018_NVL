#include "Bullet.h"
#include "Slime.h"
Bullet::Bullet() {
}

Bullet::Bullet(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture) : Sprite2D(model, shader, texture)
{
	
	this->dmg = 100;
	this->SetSize(40, 40);
}

int Bullet::getDmg() {
	return this->dmg;
}

void Bullet::Update(GLfloat deltaTime) {
	this->Set2DPosition(this->Get2DPosition().x, this->Get2DPosition().y - deltaTime * 700);
}
