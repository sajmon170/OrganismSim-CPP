#include "Human.hh"

Human* Human::createChild() const {
	return new Human(randomPosNear(), world);
}

void Human::setAbility() {
	if (cooldown == 0) {
		timer = 5;
		raiseEvent("activated Alzur's shield!");
	}
}

void Human::moveUp() {
	change = Vector2{0, -1};
}

void Human::moveDown() {
	change = Vector2{0, 1};
}

void Human::moveLeft() {
	change = Vector2{-1, 0};
}

void Human::moveRight() {
	change = Vector2{1, 0};
}

void Human::action() {
	setId();

	if (cooldown != 0) {
		cooldown--;
		if (cooldown == 0) {
			raiseEvent("can use his ability again.");
		}
	}
	
	if (timer != 0) {
		timer--;

		if (timer == 0) {
			raiseEvent("'s ability wore down...");
		}
		cooldown = 5;
	}
	
	if (change != Vector2{0, 0}) {
		Animal::move(getPos() + change);
		change = Vector2{0, 0};
	}
}

CollisionData Human::collision(Organism* organism) {
	if (timer > 0)
		return CollisionData::Builder()
			.setHappened()
			.setPushed()
			.build();

	return Animal::collision(organism);
}
