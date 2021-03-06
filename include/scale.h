#ifndef OMEGA_SCALE
#define OMEGA_SCALE

#include <string>
#include <array>

enum class ScaleType
{
	MAJOR,
	MINOR,
	DORIAN,
	PHRYGIAN,
	LYDIAN,
	MIXOLYDIAN,
	MAJOR_BLUES,
	MINOR_BLUES
};

class Scale
{
public:
	using scale_t = std::array<unsigned char, 14>;
	using scheme_t = std::array<int, 14>;

	Scale(ScaleType scaleType, const std::string& Key);

	scale_t getScale() const { return m_scale; };
	scheme_t getScheme() const { return m_scheme; };
	void setScheme(ScaleType scaleType);
	void constructScale();
private:
	ScaleType m_scaleType;
	std::string m_key;

	// two octaves -> 14 notes + 2 --> 0000 - pause, 1111 - continue previous note
	scale_t m_scale;
	scheme_t m_scheme;
};
#endif // !OMEGA_SCALE