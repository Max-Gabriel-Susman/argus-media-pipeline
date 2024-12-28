# Argus Media Pipeline

Argus Media Pipeline is the Argus Platform's library for stream management. It's intended to be included as a git submodule.

## Dependencies

* gstreamer

## Usage

1. Navigate to your project's root directory.

2. Add the C library repository as a submodule(This clones the C library repository into the specified directory):
```
git submodule add https://github.com/Max-Gabriel-Susman/argus-media-pipeline.git internal/stream/libpipeline
```

4. Initialize and update the submodule:
```
git submodule update --init --recursive
```

5. Commit the change in your main repository:
```
git commit -am "included argus-media-pipeline as a submodule"
```