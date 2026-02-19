namespace bundlemod;

using System.Runtime.InteropServices;
using System;
using System.IO;
using System.Text;
using Microsoft.Win32.SafeHandles;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Collections.Generic;

public partial class BundleMod
{
    [JsonSerializable(typeof(TextureChange))]
    [JsonSerializable(typeof(Dictionary<string, TextureChange>))]
    internal partial class SourceGenerationContext : JsonSerializerContext {}

    public static void ChangeTextures(
        SafeFileHandle fromFile, SafeFileHandle toFile, string textureChangesJson
    ) {
        Dictionary<string, TextureChange>? textureChanges = JsonSerializer.Deserialize(
            textureChangesJson, SourceGenerationContext.Default.DictionaryStringTextureChange
        );

        if (textureChanges != null) {
            using (var fromFileStream = new FileStream(fromFile, FileAccess.Read)) {
                using (var toFileStream = new FileStream(toFile, FileAccess.Write)) {
                    TextureSwap.ChangeTextures(fromFileStream, toFileStream, textureChanges);
                }
            }
        }
    }

    [UnmanagedCallersOnly(EntryPoint = "BundleMod_ChangeTextures")]
    public unsafe static void ChangeTexturesEntry(
        IntPtr fromFile, IntPtr toFile, IntPtr textureChanges
    ) {
        var fromFileHandle = new SafeFileHandle(fromFile, true);
        var toFileHandle = new SafeFileHandle(toFile, true);
        var textureChangesStr = Marshal.PtrToStringUTF8(textureChanges);
        ChangeTextures(fromFileHandle, toFileHandle, textureChangesStr);
    }
}
