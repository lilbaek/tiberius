#include "sds.h"

#ifndef CORE_TEXTURES_H
#define CORE_TEXTURES_H

// terrain
#define TEXTURE_TERRAIN_NAME "terrain"
#define TEXTURE_UGLY_GRASS "ugly_grass_01"
#define TEXTURE_EARTHQUAKE "earthquake_01"
#define TEXTURE_GRASS_1 "grass_1_01"
#define TEXTURE_GRASS_2 "grass_2_01"
#define TEXTURE_MEADOW_PREFIX "meadow_"
#define TEXTURE_SHRUB_PREFIX "shrub_"
#define TEXTURE_TREE_PREFIX "tree_"
#define TEXTURE_ELEVATION_PREFIX "elevation_"
#define TEXTURE_ACCESS_RAMP_PREFIX "access_ramp_"
#define TEXTURE_WATER "water_01"
#define TEXTURE_ELEVATION_ROCK_PREFIX "elevation_rock_"
#define TEXTURE_ROCK_PREFIX "rock_"

// basic
#define TEXTURE_BASIC_NAME "basic"
#define TEXTURE_BASIC_ROAD "road_01"
#define TEXTURE_BASIC_OVERLAY "overlay_01"
#define TEXTURE_BASIC_FLAT_TILE "flat_tile_01"

// housing
#define TEXTURE_HOUSING_NAME "housing"
#define TEXTURE_HOUSING_TENT "tent_01"
#define TEXTURE_HOUSING_SHACK "shack_01"
#define TEXTURE_HOUSING_HOVEL "hovel_01"
#define TEXTURE_HOUSING_CASA "casa_01"
#define TEXTURE_HOUSING_INSULA_1 "insula_1_01"
#define TEXTURE_HOUSING_INSULA_2 "insula_2_01"
#define TEXTURE_HOUSING_VILLA_1 "villa_1_01"
#define TEXTURE_HOUSING_VILLA_2 "villa_2_01"
#define TEXTURE_HOUSING_PALACE_1 "palace_1_01"
#define TEXTURE_HOUSING_PALACE_2 "palace_2_01"
#define TEXTURE_HOUSING_VACANT "vacant_01"

// building
#define TEXTURE_BUILDING_NAME "building"
#define TEXTURE_BUILDING_MARKET "market_01"
#define TEXTURE_BUILDING_MARKET_FANCY "market_02"
#define TEXTURE_BUILDING_WELL "well_01"
#define TEXTURE_BUILDING_WALL "wall_"
#define TEXTURE_BUILDING_GATEHOUSE "gatehouse_"

unsigned int get_terrain_image_id(sds image_name);
unsigned int get_terrain_image_id_prefix(char *prefix, int index);

unsigned int get_basic_image_id(sds image_name);
unsigned int get_basic_image_id_prefix(char *prefix, int index);

sds get_image_name(char *prefix, int index);

unsigned int get_housing_image_id_prefix(char *prefix, int index);
unsigned int get_building_image_id_prefix(char *prefix, int index);

unsigned int get_image_id_prefix(char *assetlist_name, char *prefix, int index);

#endif // CORE_TEXTURES_H