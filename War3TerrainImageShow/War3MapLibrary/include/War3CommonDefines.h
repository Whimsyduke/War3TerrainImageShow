#ifndef WAR3COMMONDEFINES_H
#define WAR3COMMONDEFINES_H

#define WAR3DEFINE_TERRAIN_TILESIZE 64

#define WAR3DEFINE_COMMON_ISVALID(war3Class) war3Class.IsValid()
#define WAR3DEFINE_COMMON_RETURNIFNOTVALID(war3Class, returns) if (! WAR3DEFINE_COMMON_ISVALID(war3Class)) return returns
#define WAR3DEFINE_COMMON_DATA_TRANSLATE(data) ((uint) data & 0xff)
namespace LibraryWar3Map
{
}
#endif // WAR3COMMONDEFINES_H