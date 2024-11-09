#include "Fox.hh"

Fox* Fox::createChild() const {
	return new Fox(randomPosNear(), world);
}

void Fox::action() {
	auto possible_moves = Math::filter(nearPos(), [this](Vector2& pos) {
		auto field = this->world.getField(pos);
		if (!field.has_value())
			return true;

		return (*field)->getStrength() < this->getStrength();
	});

	if (!possible_moves.empty())
		move(Math::pickRandom(possible_moves));
}
