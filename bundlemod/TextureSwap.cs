namespace bundlemod;

using AssetsTools.NET;
using AssetsTools.NET.Extra;
using AssetsTools.NET.Texture;
using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;
using SixLabors.ImageSharp.Processing;
using System.Runtime.CompilerServices;

public class TextureSwap {
    public static void ChangeTextures(
        FileStream bundleIn, FileStream bundleOut, Dictionary<string, TextureChange> textureChanges
    ) {
        var manager = new AssetsManager();
        var bundleInstance = manager.LoadBundleFile(bundleIn, true);
        var bundle = bundleInstance.file;
        var fileIndex = 0;
        var assetsFileInstance = manager.LoadAssetsFileFromBundle(bundleInstance, fileIndex, false);
        var assetsFile = assetsFileInstance.file;

        foreach (var textureInfo in assetsFile.GetAssetsOfType(AssetClassID.Texture2D)) {
            var textureBase = manager.GetBaseField(assetsFileInstance, textureInfo);
            var textureName = textureBase["m_Name"].AsString;
            if (textureChanges.ContainsKey(textureName)) {
                var textureChange = textureChanges[textureName];

                var texture = TextureFile.ReadTextureFile(textureBase);
                var rawTexDat = texture.FillPictureData(assetsFileInstance);
                var texDat = texture.DecodeTextureRaw(rawTexDat);

                var image = Image.LoadPixelData<Bgra32>(texDat, texture.m_Width, texture.m_Height);
                ImageSharpColorize.Colorize(image, textureChange.H, textureChange.S, textureChange.V);
                byte[] pixelBytes = new byte[image.Width * image.Height * Unsafe.SizeOf<Rgba32>()];
                image.CopyPixelDataTo(pixelBytes);

                texture.m_TextureFormat = (int)TextureFormat.BGRA32;
                texture.EncodeTextureRaw(pixelBytes, texture.m_Width, texture.m_Height);
                texture.WriteTo(textureBase);

                textureInfo.SetNewData(textureBase);
            }
        }

        bundle.BlockAndDirInfo.DirectoryInfos[fileIndex].SetNewData(assetsFile);

        using (AssetsFileWriter writer = new AssetsFileWriter(bundleOut)) {
            bundleInstance.file.Write(writer);
        }
    }
}