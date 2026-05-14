#include "room.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Room::Room(RoomType room_type)
{
    emplace_bgs(room_type);
}

RoomType Room::get_roomtype_with_entries(bool up, bool down, bool left, bool right, ) {
    return 
}

void Room::emplace_bgs(RoomType room_type) {
    for(const RoomData& room_blueprint : ROOM_LOOKUP) {
        if(room_type == room_blueprint.type) {
            // Función auxiliar interna o lógica directa para actualizar cada capa
            auto update_layer = [](bn::optional<bn::regular_bg_ptr>& layer, const bn::regular_bg_item& bg_item) {
                if(layer) {
                    layer->set_item(bg_item);
                } else {
                    layer.emplace(bg_item.create_bg(0, 0));
                    layer->set_priority(3); // El piso debería tener mayor número (fondo)
                }
            };

            // Actualizamos cada parte de la habitación
            // Prioridad 3 para el piso (atrás), 2 para las paredes (frente al piso)
            update_layer(_bg, room_blueprint.bg);

            return; // Salimos del bucle ya que encontramos la sala
        }
    }
}
