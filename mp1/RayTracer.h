#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <iostream>
#include <string>
#include "lodepng/lodepng.h"
#include "Image.h"
#include "vec3.h"
#include "Ray.h"

class RayTracer {
    public:
        RayTracer();
        RayTracer(unsigned w, unsigned h);
        RayTracer(const RayTracer &other);
        ~RayTracer();
        RayTracer & operator=(const RayTracer &other);

        void outputImage(std::string filename) const;

        void test() const;
        void setImage(const Image &im);
        void setImageSize(unsigned w, unsigned h);

        Image * image;
        void render(bool ortho);

        bool antialias;
        int aa_factor;

    private:
        void _copy(const RayTracer &other);
        void _clear();

        vec3 color(const Ray &r);
        float hitSphere(const vec3 &center, float radius, const Ray &r);
};

#endif
