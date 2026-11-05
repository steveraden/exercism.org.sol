#pragma once
namespace triangle {

	enum class flavor {
		equilateral,
        isosceles,
        scalene
	};

    flavor kind(int a, int b, int c);
}  // namespace triangle
