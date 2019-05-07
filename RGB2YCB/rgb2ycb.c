#include <stdio.h>

struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

struct YCbCr
{
	float Y;
	float Cb;
	float Cr;
};

struct YCbCr RGBToYCbCr(struct RGB rgb) {
	float fr = (float)rgb.R / 255;
	float fg = (float)rgb.G / 255;
	float fb = (float)rgb.B / 255;

	struct YCbCr ycbcr;
	ycbcr.Y = (float)(0.2989 * fr + 0.5866 * fg + 0.1145 * fb);
	ycbcr.Cb = (float)(-0.1687 * fr - 0.3313 * fg + 0.5000 * fb);
	ycbcr.Cr = (float)(0.5000 * fr - 0.4184 * fg - 0.0816 * fb);

	return ycbcr;
}

int main()
{
	struct RGB data = { 82, 0, 87 };
	struct YCbCr value = RGBToYCbCr(data);

	printf("Y:%f Cb:%f Cr:%f \n\t",value.Y,value.Cb,value.Cr);

	return 0;

}
