#pragma once

namespace math
{
	struct Vector3;
	struct Mat4
	{
		//double m[16];
		float m[16];

		Mat4();
		Mat4(float const matrix[16]);
		Mat4(float const, float const, float const , float const , float const, float const , float const , float const, float const, float const, float const, float const, float const, float const, float const, float const);
		~Mat4();


		Mat4 MatrixTranslation(Vector3 );
		Mat4 MatrixScale(Vector3 const);
		static Mat4 MatrixRotateY(float const angle);
		static Mat4 MatrixRotateX(float const angle);
		static Mat4 MatrixRotateZ(float const angle);

		Mat4 ProjectionMatrix(float const aspectRatio, float const fov, float const near, float const far);

		Mat4 Inverse();
		const static Mat4 Identity;

		Mat4 GetRevertedMatrix() const;

		Mat4 operator*(Mat4 const& matrix) const;
		Vector3 operator*(Vector3);
		Mat4 operator*=(Mat4 const& matrix);
		Mat4 operator+(Mat4& matrix)const;

		auto Print() const -> void;

		void SetMatrix(float mat[16]);

		std::string Serialize();
		Mat4* Deserialize(std::string& data);
	};
}
