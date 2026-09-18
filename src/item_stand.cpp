#include "item_stand.h"
#include "bn_sprite_items_itemstand.h"

#include "bn_fixed_point.h"

Item_stand::Item_stand(int item_id, bn::fixed_point position) {
    _item_id = item_id;
    _position = position;
    _sprite = bn::sprite_items::itemstand.create_sprite(_position);
    _sprite_anim.emplace(
        bn::sprite_animate_action<8>::forever(
            _sprite,
            5,
            bn::sprite_items::itemstand.tiles_item(),
            bn::array<uint16_t, 8>{ 0, 1, 2, 3, 4, 5, 6, 7}
        )
    );
}

Item_stand::update() {
    if(_sprite_anim) {
        _sprite_anim->update();
    }
}