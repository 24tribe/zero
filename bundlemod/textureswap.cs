using AssetsTools.NET;
using AssetsTools.NET.Extra;
using AssetsTools.NET.Texture;
using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;
using SixLabors.ImageSharp.Processing;
using System.Runtime.CompilerServices;

if (args.Length != 3) {
    Console.WriteLine("Usage: textureswap bundle_in texture_png bundle_out");
    return 1;
}

var bundleInPath = args[0];
var texturePath = args[1];
var bundleOutPath = args[2];

Console.WriteLine($"bundleInPath: {bundleInPath}");
Console.WriteLine($"texturePath: {texturePath}");
Console.WriteLine($"bundleOutPath: {bundleOutPath}");

var textureName = Path.GetFileName(texturePath).Split(".")[0];
Console.WriteLine($"textureName: {textureName}");

var manager = new AssetsManager();
var bundleInstance = manager.LoadBundleFile(bundleInPath, true);
var bundle = bundleInstance.file;
var fileIndex = 0;
var assetsFileInstance = manager.LoadAssetsFileFromBundle(bundleInstance, fileIndex, false);
var assetsFile = assetsFileInstance.file;

foreach (var textureInfo in assetsFile.GetAssetsOfType(AssetClassID.Texture2D)) {
    var textureBase = manager.GetBaseField(assetsFileInstance, textureInfo);
    if (textureBase["m_Name"].AsString == textureName) {
        Console.WriteLine("Found!!");
        var texture = TextureFile.ReadTextureFile(textureBase);
        Console.WriteLine($"{(TextureFormat)texture.m_TextureFormat}");
        var rawTexDat = texture.FillPictureData(assetsFileInstance);
        var texDat = texture.DecodeTextureRaw(rawTexDat);
        var image = Image.LoadPixelData<Bgra32>(texDat, texture.m_Width, texture.m_Height);
        image.Mutate(i => i.Rotate(RotateMode.Rotate90));
        image.SaveAsPng("texture.png");

        byte[] pixelBytes = new byte[image.Width * image.Height * Unsafe.SizeOf<Rgba32>()];
        image.CopyPixelDataTo(pixelBytes);

        texture.m_TextureFormat = (int)TextureFormat.BGRA32;
        texture.EncodeTextureRaw(pixelBytes, texture.m_Width, texture.m_Height);
        texture.WriteTo(textureBase);

        textureInfo.SetNewData(textureBase);
        break;
    }
}

bundle.BlockAndDirInfo.DirectoryInfos[fileIndex].SetNewData(assetsFile);

using (AssetsFileWriter writer = new AssetsFileWriter(bundleOutPath)) {
    bundleInstance.file.Write(writer);
}

return 0;