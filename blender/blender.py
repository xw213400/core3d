import bpy

for obj in bpy.data.objects:
    print(obj.name)

if "Cube" in bpy.data.meshes:
    mesh = bpy.data.meshes["Cube"]
    bpy.data.meshes.remove(mesh)

bpy.ops.import_scene.fbx(filepath="/Users/xie/Desktop/blender/women_b.fbx")


for obj in bpy.data.objects:
    print(obj.name)

# bpy.context.scene.render.engine = 'BLENDER_RENDER'

bpy.data.scenes['Scene'].render.filepath = '/Users/xie/Desktop/blender/render.jpg'
bpy.ops.render.render( write_still=True )