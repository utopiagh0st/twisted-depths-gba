#include "environment.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Environment::Environment(RoomType room_type)
{
    emplace_bgs(room_type);
}

void Environment::emplace_bgs(RoomType room_type) {
    for(const RoomData& room : ROOM_LOOKUP) {
        if(room_type == room.type) {
            // Función auxiliar interna o lógica directa para actualizar cada capa
            auto update_layer = [](bn::optional<bn::regular_bg_ptr>& layer, const bn::regular_bg_item& item) {
                if(layer) {
                    layer->set_item(item);
                } else {
                    layer.emplace(item.create_bg(0, 0));
                    layer->set_priority(3); // El piso debería tener mayor número (fondo)
                }
            };

            // Actualizamos cada parte de la habitación
            // Prioridad 3 para el piso (atrás), 2 para las paredes (frente al piso)
            update_layer(_bg, room.bg);

            return; // Salimos del bucle ya que encontramos la sala
        }
    }
}
