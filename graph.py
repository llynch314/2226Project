import re
import glob
import os
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker


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
    plt.figure(figsize=(8,6))
    for fp in files:
        sizes, avgs = parse_results_file(fp)
        label = os.path.basename(fp).replace("_results.txt", "")
        plt.plot(sizes, avgs, marker="o", label=label)

    plt.xlabel("Dataset size (n)")
    plt.ylabel("Average time (ms)")
    plt.title("Sorting Algorithm Benchmark Results")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.5)

    ax = plt.gca()
    ax.yaxis.set_major_formatter(mticker.FuncFormatter(lambda x, _: f"{int(x):,}"))

    plt.tight_layout()
    plt.show()


def plot_split(files):
    slow_algos = []
    fast_algos = []

    for fp in files:
        sizes, avgs = parse_results_file(fp)
        if not sizes:
            continue
        max_avg = max(avgs)
        if max_avg > 100000:
            slow_algos.append(fp)
        else:
            fast_algos.append(fp)

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14,6), sharex=True)

    for fp in slow_algos:
        sizes, avgs = parse_results_file(fp)
        label = os.path.basename(fp).replace("_results.txt", "")
        ax1.plot(sizes, avgs, marker="o", label=label)
    ax1.set_title("Slow Algorithms")
    ax1.set_xlabel("Dataset size (n)")
    ax1.set_ylabel("Average time (ms)")
    ax1.legend()
    ax1.grid(True, linestyle="--", alpha=0.5)
    ax1.yaxis.set_major_formatter(mticker.FuncFormatter(lambda x, _: f"{int(x):,}"))

    for fp in fast_algos:
        sizes, avgs = parse_results_file(fp)
        label = os.path.basename(fp).replace("_results.txt", "")
        ax2.plot(sizes, avgs, marker="o", label=label)
    ax2.set_title("Fast Algorithms")
    ax2.set_xlabel("Dataset size (n)")
    ax2.set_ylabel("Average time (ms)")
    ax2.legend()
    ax2.grid(True, linestyle="--", alpha=0.5)
    ax2.yaxis.set_major_formatter(mticker.FuncFormatter(lambda x, _: f"{int(x):,}"))

    plt.tight_layout()
    plt.show()


def choose_dataset(files):
    base_algorithms = [
        "bubble_results.txt",
        "insertion_results.txt",
        "selection_results.txt",
        "merge_results.txt",
        "quick_results.txt",
        "shell_results.txt"
    ]

    while True:
        print("\n=== Choose Dataset Type ===")
        print("1. Random (base algorithms only)")
        print("2. Sorted")
        print("3. Reversed")
        print("0. Back to main menu")
        try:
            choice = int(input("Select dataset type: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
            continue

        if choice == 0:
            return
        elif choice == 1:
            # Only include the base algorithms for random datasets
            filtered_files = [f for f in files if os.path.basename(f).lower() in base_algorithms]
        elif choice == 2:
            filtered_files = [f for f in files if "sorted" in f.lower()]
        elif choice == 3:
            filtered_files = [f for f in files if "rev" in f.lower()]
        else:
            print("Invalid choice. Try again.")
            continue

        if not filtered_files:
            print("No files found for this dataset type.")
        else:
            plot_split(filtered_files)


def main_menu():
    files = sorted(glob.glob("*results.txt"))

    if not files:
        print("No result files found in this directory.")
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
            choose_dataset(files)
        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main_menu()
