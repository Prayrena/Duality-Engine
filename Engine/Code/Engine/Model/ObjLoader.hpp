#pragma once
#include "Engine/core/Vertex_PCUTBN.hpp"
#include "Engine/core/StringUtils.hpp"
#include "Engine/Math/Mat44.hpp"
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, Rgba8> materialColorMap;

struct Vertex
{
	unsigned int m_vertexPosIndex = 0;
	unsigned int m_vertexTextureIndex = 0;
	unsigned int m_vertexNormalIndex = 0;
};

class Face
{
public:
	Rgba8 m_color = Rgba8::WHITE;
	std::vector<Vertex> vertexArray;
};

class ObjLoader
{
public:
	static bool GetMTLFileName(const std::vector<Strings>& tokensOfAllLines, std::string& mtlFName);
	static bool ReadMTLColorInfo(std::string const& filePath, std::map<std::string, materialColorMap*>& mtlInfo);
	static std::string NormalizeLineEndings(std::string const& content);
	static bool Load(std::string const& fileName,
		std::vector<Vertex_PCUTBN>& outVertexes, std::vector<unsigned int>& outIndexes,
		bool& outHasNormals, bool& outHasUVs, Mat44 const& transform = Mat44());
	static Vertex_PCUTBN AddVertexToVertexList(std::vector<Vertex_PCUTBN>& outVertexes, Vertex vertexInfo, bool outHasUVs, bool outHasNormals, 
			std::vector<Vec3> posList, std::vector<Vec3> normalsList, std::vector<Vec2> UVsList, Rgba8 vertexColor = Rgba8::WHITE, Mat44 const& transform = Mat44());
};