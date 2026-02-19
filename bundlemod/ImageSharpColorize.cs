namespace bundlemod;

using SixLabors.ImageSharp;
using SixLabors.ImageSharp.Processing;
using SixLabors.ImageSharp.PixelFormats;

// [Inspirated by Gimp colorize](https://github.com/GNOME/gimp/blob/master/app/operations/gimpoperationcolorize.c)

public class Program {
    // [Formula to determine perceived brightness of RGB color](https://stackoverflow.com/a/56678483)
    static public float CalcLum(ref Rgba32 pixel) {
        var vR = (float)pixel.R / 255;
        var vG = (float)pixel.G / 255;
        var vB = (float)pixel.B / 255;

        return (0.2126f * vR + 0.7152f * vG + 0.0722f * vB);
    }

    // [math behind hsv to rgb conversion of colors](https://stackoverflow.com/q/51203917)
    static public Rgba32 HsvToRgb(float h, float s, float v) {
        var r = 0f;
        var g = 0f;
        var b = 0f;

        var i = (float)Math.Floor(h*6f);
        var f = h * 6f - i;
        var p = v * (1f - s);
        var q = v * (1f - f * s);
        var t = v * (1f - (1f - f) * s);

        switch(i % 6f){
        case 0: {r = v; g = t; b = p; break;}
        case 1: {r = q; g = v; b = p; break;}
        case 2: {r = p; g = v; b = t; break;}
        case 3: {r = p; g = q; b = v; break;}
        case 4: {r = t; g = p; b = v; break;}
        case 5: {r = v; g = p; b = q; break;}
        }
        return new Rgba32((byte)(r*255f), (byte)(g*255f), (byte)(b*255f));
    }

    static public void Main() {
        using (Image<Rgba32> image = Image.Load<Rgba32>("texture.png")) {
            // [0, 1]
            var hue = 0.5f;

            // [0, 1]
            var saturation = 1f;

            // [-1, 1]
            var lightness = 0.0f; 

            image.ProcessPixelRows(accessor => {
                for (int y = 0; y < accessor.Height; ++y) {
                    Span<Rgba32> pixelRow = accessor.GetRowSpan(y);
                    for (int x = 0; x < pixelRow.Length; ++x) {
                        ref Rgba32 pixel = ref pixelRow[x];
                        var lum = CalcLum(ref pixel);
                        pixel.R = (byte)(255*lum);
                        pixel.G = (byte)(255*lum);
                        pixel.B = (byte)(255*lum);

                        if (lightness > 0f) {
                            lum *= (1.0f - lightness);
                            lum += 1.0f - (1.0f - lightness);
                        } else if (lightness < 0f) {
                            lum *= (lightness + 1);
                        }

                        pixel = HsvToRgb(hue, saturation, lum);
                    }
                }
            });

            image.Save("out.png"); 
        } 
    }
}