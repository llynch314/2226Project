import re
import glob
import os
import matplotlib.pyplot as plt

def parse_results_file(filename):
    sizes = []
    averages = []
    with open(filename, "r") as f:
        for line in f:
            match = re.search(r"Data size:\s*(\d+)", line)
            if match:
                size = int(match.group(1))
            avg_match = re.search(r"Average time:\s*([\deE\+\.-]+)", line)
            if avg_match:
                avg = float(avg_match.group(1))
                sizes.append(size)
                averages.append(avg)
    return sizes, averages


def plot_single(files):
    """Plot normally (for one file selection)."""
    plt.figure(figsize=(8,6))
    for fp in files:
        sizes, avgs = parse_results_file(fp)
        plt.plot(sizes, avgs, marker="o", label=os.path.basename(fp))

    plt.xlabel("Dataset size (n)")
    plt.ylabel("Average time (ms)")
    plt.title("Sorting Algorithm Benchmark Results")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.show()


def plot_split(files):
    """Split into slow vs fast (for all files)."""
    slow_algos = []
    fast_algos = []

    for fp in files:
        sizes, avgs = parse_results_file(fp)
        if not sizes:
            continue
        max_avg = max(avgs)
        if max_avg > 100000:  # threshold in ms → slow
            slow_algos.append(fp)
        else:
            fast_algos.append(fp)

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14,6), sharex=True)

    # Panel 1: slow algorithms
    for fp in slow_algos:
        sizes, avgs = parse_results_file(fp)
        ax1.plot(sizes, avgs, marker="o", label=os.path.basename(fp))
    ax1.set_title("Slow Algorithms")
    ax1.set_xlabel("Dataset size (n)")
    ax1.set_ylabel("Average time (ms)")
    ax1.legend()
    ax1.grid(True, linestyle="--", alpha=0.5)

    # Panel 2: fast algorithms
    fast_colors = {
        "Merge_results.txt": "#1f77b4",   # blue
        "Quick_results.txt": "#2ca02c",   # green
        "Shell_results.txt": "#d62728",   # red
        "Insertion_results.txt": "#ff7f0e" # orange
    }

    for fp in fast_algos:
        sizes, avgs = parse_results_file(fp)
        fname = os.path.basename(fp)
        color = fast_colors.get(fname, None)  # fallback auto if not mapped
        ax2.plot(sizes, avgs, marker="o", color=color, label=fname)

    ax2.set_title("Fast Algorithms")
    ax2.set_xlabel("Dataset size (n)")
    ax2.set_ylabel("Average time (ms)")
    ax2.legend()
    ax2.grid(True, linestyle="--", alpha=0.5)

    plt.tight_layout()
    plt.show()


def main_menu():
    files = sorted(glob.glob("*_results.txt"))
    if not files:
        print("No *_results.txt files found in this directory.")
        return

    while True:
        print("\n=== Benchmark Graph Menu ===")
        for i, f in enumerate(files, start=1):
            print(f"{i}. {f}")
        print(f"{len(files)+1}. All files (split view)")
        print("0. Exit")

        try:
            choice = int(input("Select a dataset option: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
            continue

        if choice == 0:
            break
        elif 1 <= choice <= len(files):
            selected_files = [files[choice-1]]
            plot_single(selected_files)
        elif choice == len(files)+1:
            plot_split(files)
        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main_menu()
