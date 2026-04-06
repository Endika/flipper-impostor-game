#include "include/domain/word_bank.h"

typedef struct {
  const char *en_w;
  const char *es_w;
  const char *en_h;
  const char *es_h;
} WordRow;

/* Hints: broad category or trait bucket — the word fits inside, not a
 * definition. */
static const WordRow k_rows[] = {
    {"Apple", "Manzana", "Dessert", "Postre"},
    {"Bridge", "Puente", "Infrastructure", "Infraestructura"},
    {"Castle", "Castillo", "Medieval", "Medieval"},
    {"Diamond", "Diamante", "Jewelry", "Joyeria"},
    {"Engine", "Motor", "Mechanics", "Mecanica"},
    {"Forest", "Bosque", "Nature", "Naturaleza"},
    {"Guitar", "Guitarra", "Instrument", "Instrumento"},
    {"Harbor", "Puerto", "Coast", "Costa"},
    {"Island", "Isla", "Geography", "Geografia"},
    {"Jungle", "Selva", "Tropics", "Tropico"},
    {"Kitchen", "Cocina", "Home", "Hogar"},
    {"Lighthouse", "Faro", "Navigation", "Navegacion"},
    {"Mountain", "Monte", "Outdoor", "Exterior"},
    {"Notebook", "Cuaderno", "Stationery", "Papeleria"},
    {"Ocean", "Oceano", "Marine", "Marino"},
    {"Pyramid", "Piramide", "Ancient", "Antiguo"},
    {"Quartz", "Cuarzo", "Mineral", "Mineral"},
    {"River", "Rio", "Freshwater", "Agua dulce"},
    {"School", "Escuela", "Education", "Educacion"},
    {"Tunnel", "Tunel", "Transit", "Transito"},
    {"Umbrella", "Paraguas", "Weather", "Tiempo"},
    {"Volcano", "Volcan", "Geology", "Geologia"},
    {"Window", "Ventana", "Architecture", "Arquitectura"},
    {"Xylophone", "Xilofono", "Percussion", "Percusion"},
    {"Yacht", "Yate", "Luxury", "Lujo"},
    {"Zebra", "Cebra", "Savanna", "Sabana"},
    {"Anchor", "Ancla", "Nautical", "Nautico"},
    {"Battery", "Bateria", "Energy", "Energia"},
    {"Candle", "Vela", "Celebration", "Celebracion"},
    {"Dragon", "Dragon", "Fantasy", "Fantasia"},
    {"Eagle", "Aguila", "Bird", "Ave"},
    {"Feather", "Pluma", "Light", "Ligero"},
    {"Galaxy", "Galaxia", "Space", "Espacio"},
    {"Helmet", "Casco", "Safety", "Seguridad"},
    {"Iceberg", "Iceberg", "Polar", "Polar"},
    {"Jacket", "Chaqueta", "Clothing", "Ropa"},
    {"Key", "Llave", "Access", "Acceso"},
    {"Lantern", "Linterna", "Camping", "Camping"},
    {"Meteor", "Meteoro", "Night sky", "Cielo nocturno"},
    {"Necklace", "Collar", "Accessory", "Accesorio"},
};

uint16_t word_bank_word_count(void) {
  return (uint16_t)(sizeof(k_rows) / sizeof(k_rows[0]));
}

void word_bank_get_pair(uint16_t index, ImpostorLocale locale,
                        const char **word_out, const char **hint_out) {
  if (!word_out || !hint_out) {
    return;
  }
  const uint16_t n = word_bank_word_count();
  const uint16_t i = (uint16_t)(index % n);
  const WordRow *row = &k_rows[i];
  if (locale == ImpostorLocaleEs) {
    *word_out = row->es_w;
    *hint_out = row->es_h;
  } else {
    *word_out = row->en_w;
    *hint_out = row->en_h;
  }
}
