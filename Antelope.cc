#include "Antelope.hh"

Antelope* Antelope::createChild() const {
	return new Antelope(randomPosNear(), world);
}

void Antelope::action() {
	for (int i=0; i<2; i++)
		move();
}

CollisionData Antelope::collision(Organism* organism) {
	if (not Math::chance(0.5)) {
		return Animal::collision(organism);
	}
	
	auto possible_moves = Math::filter(nearPos(), [this](Vector2 pos) {
		return not this->world.getField(pos).has_value();
	});

	if (possible_moves.empty())
		return Animal::collision(organism);
	
	move(Math::pickRandom(possible_moves));
	return CollisionData::Builder()
			.setHappened()
			.build();
}
